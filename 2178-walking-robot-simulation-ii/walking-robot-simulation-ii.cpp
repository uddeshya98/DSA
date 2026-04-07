class Robot {
public:
    int w, h, x = 0, y = 0, dir = 1;
    int per;

    Robot(int width, int height) {
        w = width;
        h = height;
        per = 2 * (w + h) - 4;
    }
    
    void step(int num) {
        num %= per;
        if (num == 0) num = per;
        
        while (num--) {
            int nx = x, ny = y;
            if (dir == 0) ny++;
            else if (dir == 1) nx++;
            else if (dir == 2) ny--;
            else nx--;
            
            if (nx < 0 || nx >= w || ny < 0 || ny >= h) {
                dir = (dir + 3) % 4;
                num++;
            } else {
                x = nx;
                y = ny;
            }
        }
    }
    
    vector<int> getPos() {
        return {x, y};
    }
    
    string getDir() {
        if (dir == 0) return "North";
        if (dir == 1) return "East";
        if (dir == 2) return "South";
        return "West";
    }
};