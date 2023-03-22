class Robot {
    int pos = 0; 
    int width = 0;
    int height = 0;
    int perimetr = 0;
public:
    Robot(int width, int height):width(width - 1), height(height - 1){
         perimetr = (this->width * 2 + this->height * 2);
    }
    
    void step(int num) {
        pos += num;
        
        //if ( pos % perimetr > 0){
            //pos -= (pos / perimetr) * perimetr;
        pos %= perimetr;
        //}
        if(pos == 0){
            pos = perimetr;
        }
        //cout << pos << " " << perimetr << endl;
    }
    
    vector<int> getPos() {
        
        if (pos >= 0 && pos <= width){
            return {pos,0};
        }
        else if (pos > width && pos <= height + width){
            return {width, pos - width};
        }
        else if (pos > height + width && pos <= height + width * 2){
            return { (height + width * 2) - pos, height};
        }
        else{
            return { 0, (height * 2 + width * 2) - pos};
        }
    }
    
    string getDir() {
        if (pos >= 0 && pos <= width){
            return "East";
        }
        else if (pos > width && pos <= height + width){
            return "North";
        }
        else if (pos > height + width && pos <= height + width * 2){
            return "West";
        }
        else{
            return "South";
        }
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */