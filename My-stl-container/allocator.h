//
// Created by kd on 02/02/23.
//

#ifndef MY_STL_CONTAINER_ALLOCATOR_H
#define MY_STL_CONTAINER_ALLOCATOR_H
#include <cstdint>
#include <memory>

#include <iostream>

using std::size_t;

using std::cout;
using std::endl;

template <class T>
class My_allocator{

public:
    T* allocate(size_t size){
        cout << "allocate " << size << endl;
        return static_cast<T*>(::operator new(size * sizeof(T)));
    }

    template<class ...Args>
    void construct(T *t, Args ...args){
        cout << "construct" << endl;
        new (t) T(std::forward<Args>(args)...);
    }

    void destroy(T *t){
        t->~T();
    }

    void deallocate(T *t, size_t size){
        ::operator delete(t, size);
    }
};

template <class T, size_t grow_size = 1024>
class Static_allocator{

    uint8_t buf[grow_size * sizeof(T)];

public:
    T* allocate(size_t size){
        cout << "allocate " << size << endl;
        return static_cast<T*>(::operator new(size * sizeof(T)));
    }

    template<class ...Args>
    void construct(T *t, Args ...args){
        cout << "construct" << endl;
        new (t) T(std::forward<Args>(args)...);
    }

    void destroy(T *t){
        t->~T();
    }

    void deallocate(T *t, size_t size){
        ::operator delete(t, size);
    }
};


namespace Moya {

template<class T, std::size_t growSize = 1024>
class MemoryPool {
    struct Block {
        Block *next;
    };

    class Buffer {
        static const std::size_t blockSize = sizeof(T) > sizeof(Block) ? sizeof(T) : sizeof(Block);
        uint8_t data[blockSize * growSize];

    public:

        Buffer *const next;

        Buffer(Buffer *next) :
                next(next) {
        }

        T *getBlock(std::size_t index) {
            return reinterpret_cast<T *>(&data[blockSize * index]);
        }
    };

    Block *firstFreeBlock = nullptr;
    Buffer *firstBuffer = nullptr;
    std::size_t bufferedBlocks = growSize;

public:

    MemoryPool() = default;

    MemoryPool(MemoryPool &&memoryPool) = delete;

    MemoryPool(const MemoryPool &memoryPool) = delete;

    MemoryPool operator=(MemoryPool &&memoryPool) = delete;

    MemoryPool operator=(const MemoryPool &memoryPool) = delete;

    ~MemoryPool() {
        while (firstBuffer) {
            Buffer *buffer = firstBuffer;
            firstBuffer = buffer->next;
            delete buffer;
        }
    }

    T *allocate() {
        if (firstFreeBlock) {
            Block *block = firstFreeBlock;
            firstFreeBlock = block->next;
            return reinterpret_cast<T *>(block);
        }

        if (bufferedBlocks >= growSize) {
            firstBuffer = new Buffer(firstBuffer);
            bufferedBlocks = 0;
        }

        return firstBuffer->getBlock(bufferedBlocks++);
    }

    void deallocate(T *pointer) {
        Block *block = reinterpret_cast<Block *>(pointer);
        block->next = firstFreeBlock;
        firstFreeBlock = block;
    }
};

template<class T, std::size_t growSize = 1024>
class Allocator : private MemoryPool<T, growSize> {
#if defined(_WIN32) && defined(ENABLE_OLD_WIN32_SUPPORT)
    Allocator *copyAllocator = nullptr;
    std::allocator<T> *rebindAllocator = nullptr;
#endif

public:

    typedef std::size_t size_type;
    typedef std::ptrdiff_t difference_type;
    typedef T *pointer;
    typedef const T *const_pointer;
    typedef T &reference;
    typedef const T &const_reference;
    typedef T value_type;

    template<class U>
    struct rebind {
        typedef Allocator<U, growSize> other;
    };

#if defined(_WIN32) && defined(ENABLE_OLD_WIN32_SUPPORT)
    Allocator() = default;

        Allocator(Allocator &allocator) :
            copyAllocator(&allocator)
        {
        }

        template <class U>
        Allocator(const Allocator<U, growSize> &other)
        {
            if (!std::is_same<T, U>::value)
                rebindAllocator = new std::allocator<T>();
        }

        ~Allocator()
        {
            delete rebindAllocator;
        }
#endif

    pointer allocate(size_type n, const void *hint = 0) {
#if defined(_WIN32) && defined(ENABLE_OLD_WIN32_SUPPORT)
        if (copyAllocator)
                return copyAllocator->allocate(n, hint);

            if (rebindAllocator)
                return rebindAllocator->allocate(n, hint);
#endif

        // if (n != 1 || hint)
        //    throw std::bad_alloc();

        return MemoryPool<T, growSize>::allocate();
    }

    void deallocate(pointer p, size_type n) {
#if defined(_WIN32) && defined(ENABLE_OLD_WIN32_SUPPORT)
        if (copyAllocator) {
                copyAllocator->deallocate(p, n);
                return;
            }

            if (rebindAllocator) {
                rebindAllocator->deallocate(p, n);
                return;
            }
#endif

        MemoryPool<T, growSize>::deallocate(p);
    }

    void construct(pointer p, const_reference val) {
        new(p) T(val);
    }

    void destroy(pointer p) {
        p->~T();
    }
};
}

#include <cstddef>
#include <cstdint>

namespace st_alloc{

template <std::size_t N, std::size_t alignment = alignof(std::max_align_t)>
class arena
{
    alignas(alignment) char buf_[N];
    char* ptr_;

public:
    ~arena() {ptr_ = nullptr;}
    arena() noexcept : ptr_(buf_) {}
    arena(const arena&) = delete;
    arena& operator=(const arena&) = delete;

    template <std::size_t ReqAlign> char* allocate(std::size_t n);
    void deallocate(char* p, std::size_t n) noexcept;

    static constexpr std::size_t size() noexcept {return N;}
    std::size_t used() const noexcept {return static_cast<std::size_t>(ptr_ - buf_);}
    void reset() noexcept {ptr_ = buf_;}

private:
    static
    std::size_t
    align_up(std::size_t n) noexcept
    {return (n + (alignment-1)) & ~(alignment-1);}

    bool
    pointer_in_buffer(char* p) noexcept
    {
        return std::uintptr_t(buf_) <= std::uintptr_t(p) &&
               std::uintptr_t(p) <= std::uintptr_t(buf_) + N;
    }
};

template <std::size_t N, std::size_t alignment>
template <std::size_t ReqAlign>
char*
arena<N, alignment>::allocate(std::size_t n)
{
    static_assert(ReqAlign <= alignment, "alignment is too small for this arena");
    assert(pointer_in_buffer(ptr_) && "short_alloc has outlived arena");
    auto const aligned_n = align_up(n);
    if (static_cast<decltype(aligned_n)>(buf_ + N - ptr_) >= aligned_n)
    {
        char* r = ptr_;
        ptr_ += aligned_n;
        return r;
    }

    static_assert(alignment <= alignof(std::max_align_t), "you've chosen an "
                                                          "alignment that is larger than alignof(std::max_align_t), and "
                                                          "cannot be guaranteed by normal operator new");
    return static_cast<char*>(::operator new(n));
}

template <std::size_t N, std::size_t alignment>
void
arena<N, alignment>::deallocate(char* p, std::size_t n) noexcept
{
    assert(pointer_in_buffer(ptr_) && "short_alloc has outlived arena");
    if (pointer_in_buffer(p))
    {
        n = align_up(n);
        if (p + n == ptr_)
            ptr_ = p;
    }
    else
        ::operator delete(p);
}

template <class T, std::size_t N, std::size_t Align = alignof(std::max_align_t)>
class short_alloc
{
public:
    using value_type = T;
    static auto constexpr alignment = Align;
    static auto constexpr size = N;
    using arena_type = arena<size, alignment>;

private:
    arena_type& a_;

public:
    short_alloc(const short_alloc&) = default;
    short_alloc& operator=(const short_alloc&) = delete;

    short_alloc(arena_type& a) noexcept : a_(a)
    {
        static_assert(size % alignment == 0,
                      "size N needs to be a multiple of alignment Align");
    }
    template <class U>
    short_alloc(const short_alloc<U, N, alignment>& a) noexcept
            : a_(a.a_) {}

    template <class _Up> struct rebind {using other = short_alloc<_Up, N, alignment>;};

    T* allocate(std::size_t n)
    {
        return reinterpret_cast<T*>(a_.template allocate<alignof(T)>(n*sizeof(T)));
    }
    void deallocate(T* p, std::size_t n) noexcept
    {
        a_.deallocate(reinterpret_cast<char*>(p), n*sizeof(T));
    }

    template <class T1, std::size_t N1, std::size_t A1,
            class U, std::size_t M, std::size_t A2>
    friend
    bool
    operator==(const short_alloc<T1, N1, A1>& x, const short_alloc<U, M, A2>& y) noexcept;

    template <class U, std::size_t M, std::size_t A> friend class short_alloc;
};

template <class T, std::size_t N, std::size_t A1, class U, std::size_t M, std::size_t A2>
inline
bool
operator==(const short_alloc<T, N, A1>& x, const short_alloc<U, M, A2>& y) noexcept
{
    return N == M && A1 == A2 && &x.a_ == &y.a_;
}

template <class T, std::size_t N, std::size_t A1, class U, std::size_t M, std::size_t A2>
inline
bool
operator!=(const short_alloc<T, N, A1>& x, const short_alloc<U, M, A2>& y) noexcept
{
    return !(x == y);
}

}
#endif //MY_STL_CONTAINER_ALLOCATOR_H
