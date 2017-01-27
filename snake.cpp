/*
 CS 349 A1 Skeleton Code - Snake
 
 - - - - - - - - - - - - - - - - - - - - - -
 
 Commands to compile and run:
 
 g++ -o snake snake.cpp -L/usr/X11R6/lib -lX11 -lstdc++
 ./snake
 
 Note: the -L option and -lstdc++ may not be needed on some machines.
 */

#include <iostream>
#include <list>
#include <cstdlib>
#include <sys/time.h>
#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include <string>
#include <sstream>
#include <vector>
#include <map>

/*
 * Header files for X functions
 */
#include <X11/Xlib.h>
#include <X11/Xutil.h>

using namespace std;

/*
 * Global game state variables
 */
const int Border = 1;
const int BufferSize = 10;
 int FPS;
int speed;
const int width = 800;
const int height = 600;
int score;
int aiscore;

/*
 * Information to draw on the window.
 */
struct XInfo {
    Display	 *display;
    int		 screen;
    Window	 window;
    GC		 gc[3];
    int		width;		// size of window
    int		height;
    Pixmap pixmap;  // double buffering
    
};


/*
 * Function to put out a message on error exits.
 */
void error( string str ) {
    cerr << str << endl;
    exit(0);
}


/*
 * An abstract class representing displayable things.
 */
class Displayable {
public:
    virtual void paint(XInfo &xinfo) = 0;
};


struct pos{
    int x;
    int y;
    pos(int x1, int y1){
        this->x=x1;
        this->y=y1;
    }
};

std::map<string,bool> m;


class Obstacle: public Displayable{
public:
    virtual void paint(XInfo &xinfo){
        
    //XFillRectangle(xinfo.display, xinfo.window, xinfo.gc[0], posi->x, posi->y, 10, 10);
    XFillRectangle(xinfo.display, xinfo.pixmap, xinfo.gc[0], posi->x, posi->y, 10, 10);
    }

    Obstacle(int x, int y){
        posi = new pos(x,y);
        stringstream ss,ss1;
        ss << x;
        string str = ss.str();
        ss1<<y;
        string str2 = ss1.str();
        string key = str.append(str2);
        cout<<"current pos stored"<<key<<endl;
        m[key] = true;
    }

    pos* posi;
};

vector<Obstacle*> objVec;

void initOb(int level){
    if(level == 5){
        int x1 = 0;
        int y1 = 0;
        for(int i = 0; i<=200;i = i+10){
            Obstacle * newob = new Obstacle(x1,y1+i);
            objVec.push_back(newob);
        }
        
        x1 = 0;
        y1 = 300;
        for(int i = 0; i<=200;i = i+10){
            Obstacle * newob = new Obstacle(x1,y1+i);
            objVec.push_back(newob);
        }
        x1 = 790;
        y1 = 0;
        for(int i = 0; i<=200;i = i+10){
            Obstacle * newob = new Obstacle(x1,y1+i);
            objVec.push_back(newob);
        }
        x1 = 790;
        y1 = 300;
        for(int i = 0; i<=200;i = i+10){
            Obstacle * newob = new Obstacle(x1,y1+i);
            objVec.push_back(newob);
        }
        x1 = 0;
        y1 = 0;
        for(int i = 0; i<=200;i = i+10){
            Obstacle * newob = new Obstacle(x1+i,y1);
            objVec.push_back(newob);
        }
        x1 = 300;
        y1 = 0;
        for(int i = 0; i<=200;i = i+10){
            Obstacle * newob = new Obstacle(x1+i,y1);
            objVec.push_back(newob);
        }
        x1 = 700;
        y1 = 0;
        for(int i = 0; i<=100;i = i+10){
            Obstacle * newob = new Obstacle(x1+i,y1);
            objVec.push_back(newob);
        }
        
        
        x1 = 0;
        y1 = 590;
        for(int i = 0; i<=200;i = i+10){
            Obstacle * newob = new Obstacle(x1+i,y1);
            objVec.push_back(newob);
        }
        x1 = 300;
        y1 = 590;
        for(int i = 0; i<=200;i = i+10){
            Obstacle * newob = new Obstacle(x1+i,y1);
            objVec.push_back(newob);
        }
        x1 = 700;
        y1 = 590;
        for(int i = 0; i<=100;i = i+10){
            Obstacle * newob = new Obstacle(x1+i,y1);
            objVec.push_back(newob);
        }
    }
    if(level == 1){
        return;
    }
    if(level == 2){
        int x1 = 40;
        int y1 = 0;
        
        int x2 = 200;
        int y2 = 0;
        
        int x3 = 440;
        int y3 = 0;
        
        int x4 = 700;
        int y4 = 0;
        
        for(int i = 0; i<=500;i = i+10){
            Obstacle * newob = new Obstacle(x1,y1+i);
            objVec.push_back(newob);
        }
        for(int i = 0; i<=500;i = i+10){
            Obstacle * newob = new Obstacle(x2,y2+i);
            objVec.push_back(newob);
        }
        for(int i = 0; i<=500;i = i+10){
            Obstacle * newob = new Obstacle(x3,y3+i);
            objVec.push_back(newob);
        }
        for(int i = 0; i<=500;i = i+10){
            Obstacle * newob = new Obstacle(x4,y4+i);
            objVec.push_back(newob);
        }
    }
    
    if(level == 3 || level == 4){
        int x1 = 40;
        int y1 = 600;
        
        int x2 = 200;
        int y2 = 600;
        
        int x3 = 440;
        int y3 = 600;
        
        int x4 = 700;
        int y4 = 600;
        
        int x5 = 70;
        int y5 = 0;
        
        int x6 = 230;
        int y6 = 0;
        
        int x7 = 470;
        int y7 = 0;
        
        int x8 = 730;
        int y8 = 0;
        
        for(int i = 0; i<=500;i = i+10){
            Obstacle * newob = new Obstacle(x1,y1-i);
            objVec.push_back(newob);
        }
        for(int i = 0; i<=500;i = i+10){
            Obstacle * newob = new Obstacle(x2,y2-i);
            objVec.push_back(newob);
        }
        for(int i = 0; i<=500;i = i+10){
            Obstacle * newob = new Obstacle(x3,y3-i);
            objVec.push_back(newob);
        }
        for(int i = 0; i<=500;i = i+10){
            Obstacle * newob = new Obstacle(x4,y4-i);
            objVec.push_back(newob);
        }
    
        for(int i = 0; i<=500;i = i+10){
            Obstacle * newob = new Obstacle(x5,y5+i);
            objVec.push_back(newob);
        }
        for(int i = 0; i<=500;i = i+10){
            Obstacle * newob = new Obstacle(x6,y6+i);
            objVec.push_back(newob);
        }
        for(int i = 0; i<=500;i = i+10){
            Obstacle * newob = new Obstacle(x7,y7+i);
            objVec.push_back(newob);
        }
        for(int i = 0; i<=500;i = i+10){
            Obstacle * newob = new Obstacle(x8,y8+i);
            objVec.push_back(newob);
        }
        
        if(level == 3){
            return;
        }
        
        int x9 = 10;
        int y9 = 200;
        
        int x10 = 300;
        int y10 =300;
        
        int x11 = 500;
        int y11 = 400;
        
        int x12 = 100;
        int y12 = 500;
        for(int i = 0; i<=30;i = i+10){
            Obstacle * newob = new Obstacle(x9+i,y9);
            objVec.push_back(newob);
        }
        for(int i = 90; i<=180;i = i+10){
            Obstacle * newob = new Obstacle(x9+i,y9);
            objVec.push_back(newob);
        }
        for(int i = 0; i<=140;i = i+10){
            Obstacle * newob = new Obstacle(x10+i,y10);
            objVec.push_back(newob);
        }
        for(int i = 170; i<=200;i = i+10){
            Obstacle * newob = new Obstacle(x10+i,y10);
            objVec.push_back(newob);
        }
        for(int i = 0; i<=200;i = i+10){
            Obstacle * newob = new Obstacle(x11+i,y11);
            objVec.push_back(newob);
        }
        for(int i = 0; i<=100;i = i+10){
            Obstacle * newob = new Obstacle(x12+i,y12);
            objVec.push_back(newob);
        }
        for(int i = 130; i<=200;i = i+10){
            Obstacle * newob = new Obstacle(x12+i,y12);
            objVec.push_back(newob);
        }
        
    
    }
    
    
};

class Fruit;
class Snake : public Displayable {
public:
    virtual void paint(XInfo &xinfo) {
        //XFillRectangle(xinfo.display, xinfo.window, xinfo.gc[0], x, y, 10, blockSize);
        vector<pos*>::iterator iter, end;
        for(iter = posvec.begin(), end = posvec.end() ; iter != end; ++iter){
            //XFillRectangle(xinfo.display, xinfo.window, xinfo.gc[0], (*iter)->x, (*iter)->y, 10, blockSize);
            
            //XFillRectangle(xinfo.display, xinfo.pixmap, xinfo.gc[0], (*iter)->x, (*iter)->y, 10, blockSize);
            XFillArc(xinfo.display, xinfo.pixmap, xinfo.gc[0], (*iter)->x, (*iter)->y, 10, 10, 0, 360*64);
        }
        
    }
    
    void eatSelf(){
    
        for(int ii = 1 ;ii<=posvec.size()-1; ++ii){
            
            if(posvec.at(ii)->x == posvec.at(0)->x && posvec.at(ii)->y == posvec.at(0)->y){
                this->direction = 0;
                over = true;
            }
        }
    }
    void hitobstacle(){
        stringstream ss,ss1;
        ss << getX();
        string str = ss.str();
        ss1<< getY();
        string str2 = ss1.str();
        string key = str.append(str2);
        if(m.count(key)){
            this->direction = 0;
            over = true;
        }
    
    }
    void virtual move(XInfo &xinfo){
        // ** ADD YOUR LOGIC **
        // Here, you will be performing collision detection between the snake,
        // the fruit, and the obstacles depending on what the snake lands on.
        
    
        if(direction == 0){
            return;
        }
        if(upOrNo()){
            if(direction > 0){//south!
                pos * lastInVector;
                //lastInVector = posvec.back();
                pos* temp = posvec[posvec.size()-1];
                posvec[posvec.size()-1] = NULL;
                posvec.pop_back();
                delete temp;
                vector<pos*>::iterator begin = posvec.begin();
                
                
                x = (*posvec.begin())->x;
                y = (*posvec.begin())->y+10;
                lastInVector = new pos(x,y);
                begin = posvec.insert(begin, lastInVector);
                
                
                
            }
            else{//north
            
                pos * lastInVector;
                //lastInVector = posvec.back();
                pos* temp = posvec[posvec.size()-1];
                posvec[posvec.size()-1] = NULL;
                posvec.pop_back();
                delete temp;
                vector<pos*>::iterator begin = posvec.begin();
                
                
                x = (*posvec.begin())->x;
                y = (*posvec.begin())->y-10;
                lastInVector = new pos(x,y);
                begin = posvec.insert(begin, lastInVector);
                
            }
        }
        else{
            if(direction > 0){//east
            
                pos * lastInVector;
                //lastInVector = posvec.back();
                pos* temp = posvec[posvec.size()-1];
                posvec[posvec.size()-1] = NULL;
                posvec.pop_back();
                delete temp;
                vector<pos*>::iterator begin = posvec.begin();
                
                
                x = (*posvec.begin())->x+10;
                y = (*posvec.begin())->y;
                lastInVector = new pos(x,y);
                begin = posvec.insert(begin, lastInVector);
            }
            else{//west
            
                pos * lastInVector;
                //lastInVector = posvec.back();
                pos* temp = posvec[posvec.size()-1];
                posvec[posvec.size()-1] = NULL;
                posvec.pop_back();
                delete temp;
                vector<pos*>::iterator begin = posvec.begin();
                
                
                x = (*posvec.begin())->x-10;
                y = (*posvec.begin())->y;
                lastInVector = new pos(x,y);
                begin = posvec.insert(begin, lastInVector);
            
            }
        }
        if(!up){
            
                if(x<0){
                    pos * lastInVector;
                    //lastInVector = posvec.back();
                    pos* temp = posvec[posvec.size()-1];
                    posvec[posvec.size()-1] = NULL;
                    posvec.pop_back();
                    delete temp;
                    vector<pos*>::iterator begin = posvec.begin();
                    
                    
                    x = 790;
                    y = (*posvec.begin())->y;
                    lastInVector = new pos(x,y);
                    begin = posvec.insert(begin, lastInVector);
                    
                }
                if(x>width){
                    pos * lastInVector;
                    //lastInVector = posvec.back();
                    pos* temp = posvec[posvec.size()-1];
                    posvec[posvec.size()-1] = NULL;
                    posvec.pop_back();
                    delete temp;
                    vector<pos*>::iterator begin = posvec.begin();
                    
                    
                    x = 0;
                    y = (*posvec.begin())->y;
                    lastInVector = new pos(x,y);
                    begin = posvec.insert(begin, lastInVector);
                    
                }
                //over = true;
                //direction = 0;
            
        }
        if(up){

                if(y<0){
                    pos * lastInVector;
                    //lastInVector = posvec.back();
                    pos* temp = posvec[posvec.size()-1];
                    posvec[posvec.size()-1] = NULL;
                    posvec.pop_back();
                    delete temp;
                    vector<pos*>::iterator begin = posvec.begin();
                    
                    
                    x = (*posvec.begin())->x;
                    y = 590;
                    lastInVector = new pos(x,y);
                    begin = posvec.insert(begin, lastInVector);
                }
                if(y>height){
                    pos * lastInVector;
                    //lastInVector = posvec.back();
                    pos* temp = posvec[posvec.size()-1];
                    posvec[posvec.size()-1] = NULL;
                    posvec.pop_back();
                    delete temp;
                    vector<pos*>::iterator begin = posvec.begin();
                    
                    
                    x = (*posvec.begin())->x;
                    y = 0;
                    lastInVector = new pos(x,y);
                    begin = posvec.insert(begin, lastInVector);
                }
                //over = true;
                //direction = 0
        }
        
        eatSelf();
        hitobstacle();
        
    }
    
    
    int getX() {
        return x;
    }
    
    int getY() {
        return y;
    }
    int getDirection(){
        return direction;
    }
    
    /*
     * ** ADD YOUR LOGIC **
     * Use these placeholder methods as guidance for implementing the snake behaviour.
     * You do not have to use these methods, feel free to implement your own.
     */
    void didEatFruit() {
        //length = length+10;
        pos * lastInVector = NULL;
        if(upOrNo()){
            if(direction>0){//south!
            lastInVector = new pos(x,y+10);
            vector<pos*>::iterator begin = posvec.begin();
            begin = posvec.insert(begin, lastInVector);
            }
            else{//north
                lastInVector = new pos(x,y-10);
                vector<pos*>::iterator begin = posvec.begin();
                begin = posvec.insert(begin, lastInVector);
            
            }
        
        }
        
        else{
            if(direction>0){//east
                lastInVector = new pos(x+10,y);
                vector<pos*>::iterator begin = posvec.begin();
                begin = posvec.insert(begin, lastInVector);
            }
            else{//west
            
                lastInVector = new pos(x-10,y);
                vector<pos*>::iterator begin = posvec.begin();
                begin = posvec.insert(begin, lastInVector);
            }
        }
    }
    
    void addToPosVec(pos * p){
        posvec.push_back(p);
    }
    
    
    bool upOrNo(){
        return up;
    }
    void reverse(){
        up = !up;
    }
    
    
    Snake(int x, int y): x(x), y(y) {
        direction = -10;
        blockSize = 10;
        length = 4;
        up = false;
        for(int i = 0; i < 4; ++i){
            pos* temp =  new pos(x+(i*10),y);
            posvec.push_back(temp);
        }
        
    }
    void snakeStatus(){
        cout<<"direction is"<<this->direction<<endl;
        cout<<"up?"<<this->upOrNo()<<endl;
    }
    void setDirection(int d){
        direction = d;
    }
    void pause(XInfo &xinfo){
        this->directionBackUp = direction;
        this->direction =0;
        //XDrawString(xinfo.display, xinfo.window, xinfo.gc[0],550,550, "Restart in a minute", 19);
        pausebool = true;
        
    }
    void resume(){
        this->direction = directionBackUp;
        pausebool = false;
    }
    
    vector<pos*> posvec;
    bool pausebool;
    bool over;
    bool ai;
    int x;
    int y;
    int blockSize;
    int direction;
    int directionBackUp;
    int length;
    bool up;
    
    //int turnx;
    //int turny;

};


Snake snake(400, 450);



class Fruit : public Displayable {
public:
    virtual void paint(XInfo &xinfo) {
        //XFillRectangle(xinfo.display, xinfo.window, xinfo.gc[0], x, y, 10, 10);
        XFillRectangle(xinfo.display, xinfo.pixmap, xinfo.gc[0], x, y, 10, 10);
    }
    
    Fruit() {
        // ** ADD YOUR LOGIC **
        // generate the x and y value for the fruit
        x = (rand() % 75)*10+10;
        y = (rand() % 55)*10+10;
        bigboss = &snake;
        
    }
    void ChangeLocation(){
        
        x = (rand() % 75)*10+10;
        y = (rand() % 55)*10+10;
        stringstream ss,ss1;
        ss << x;
        string str = ss.str();
        ss1<< y;
        string str2 = ss1.str();
        string key = str.append(str2);
        
        while(m.count(key)){
            x = (rand() % 75)*10+10;
            y = (rand() % 55)*10+10;
            stringstream ss,ss1;
            ss << x;
            string str = ss.str();
            ss1<< y;
            string str2 = ss1.str();
            string key = str.append(str2);
        }
    }
    void alert(){
        
        if(x == bigboss->getX() && y == bigboss->getY()){
            ChangeLocation();
            bigboss->didEatFruit();
            //bigboss->eatSelf();
            score = score + 10;
        }
        if(x == theboss->getX() && y == theboss->getY()){
            ChangeLocation();
            //theboss->didEatFruit();
            //bigboss->eatSelf();
            aiscore = aiscore + 10;
        }
    }
    int getX(){
        return x;
    }
    int getY(){
        return y;
    }
    // ** ADD YOUR LOGIC **
    /*
     * The fruit needs to be re-generated at new location every time a snake eats it. See the assignment webpage for more details.
     */
    Snake * theboss;
private:
    int x;
    int y;
    Snake * bigboss;
    
};
Fruit fruit;



struct aiSnake : public Snake{
    aiSnake(int x1, int y1): Snake(x1,y1){}
    
    void didEatFruit() {
        //length = length+10;
            }
    
    void paint(XInfo &xinfo) {
        //XFillRectangle(xinfo.display, xinfo.window, xinfo.gc[0], x, y, 10, blockSize);
        vector<pos*>::iterator iter, end;
        for(iter = posvec.begin(), end = posvec.end() ; iter != end; ++iter){
            
            XFillRectangle(xinfo.display, xinfo.pixmap, xinfo.gc[0], (*iter)->x, (*iter)->y, 10, blockSize);
            
        }
    }
    bool sig;// mark if snake has made turn or no;
    void move(XInfo &xinfo){
        sig = false;
        cout<<x<<endl;
        cout<<y<<endl;
        if(getX() <= 10 && getY() <= 10&& !upOrNo() && direction <0&& !sig){
        //up left going west
            reverse();
            direction = -direction;
            sig = 1;
        }
        if(getY() <= 10 && getX()<=10 &&upOrNo() && direction <0&& !sig){
        // up left going north
            reverse();
            direction = -direction;
            sig = 1;
        }
        if(getX() >= 780 && getY() <=10 &&!upOrNo() && direction >0&& !sig){
        //right up corner going east
            reverse();
            sig = 1;
        }
        if(getY() <= 10 && getX() >= 780 &&upOrNo() && direction <0&& !sig){
            //right up corner going north
            reverse();
            sig = 1;
        }
        if(getX() <= 10 && getY() >= 580 &&!upOrNo() && direction <0&& !sig){
        //left bottom going west
            reverse();
            sig = 1;
        }
        if(getY() >= 580 &&getX() <= 10&&upOrNo() && direction >0&& !sig){
            //left bottom going south
            reverse();
            sig = 1;
        }
        if(getX() >= 780 &&getY() >= 580&&!upOrNo() && direction >0&& !sig){
            //right bottom going east
            reverse();
            direction = - direction;
            sig = 1;
        }
        if(getY() >= 580 &&getX() >= 780&&upOrNo() && direction >0&& !sig){
            //right bottom going south
            reverse();
            direction = - direction;
            sig = 1;
        }
        
        
        
        if((getX() <= 10 || getX() >= 780) && (!upOrNo()) && !sig){
            this->reverse();
            sig = 1;
        }
        if((getY() <= 10 || getY()>=580) && (upOrNo()) && !sig){
            this->reverse();
            sig = 1;
        }
        
        
        if(fruit.getY()==this->getY() && upOrNo()){
            this->reverse();
            if(this->direction > 0){ // south
                if(fruit.getX()>this->getX()){
                }
                else{
                    this->setDirection(-this->direction);
                }
            }
            else{// north
                if(fruit.getX()>this->getX()){
                    this->setDirection(-this->direction);
                }
                else{
                }
            }
        }
        if(fruit.getX()==this->getX() && !upOrNo()){
            this->reverse();
            if(this->direction > 0){ // east
                if(fruit.getY()>this->getY()){
                }
                else{
                    this->setDirection(-this->direction);
                }
            }
            else{// west
                if(fruit.getY()>this->getY()){
                    this->setDirection(-this->direction);
                }
                else{
                }
            }
        }
        if(direction == 0){
            return;
        }
        if(upOrNo()){
            if(direction > 0){//south!
                
                
                
                pos * lastInVector;
                //lastInVector = posvec.back();
                pos* temp = posvec[posvec.size()-1];
                posvec[posvec.size()-1] = NULL;
                posvec.pop_back();
                delete temp;
                vector<pos*>::iterator begin = posvec.begin();
                
                
                x = (*posvec.begin())->x;
                y = (*posvec.begin())->y+10;
                lastInVector = new pos(x,y);
                begin = posvec.insert(begin, lastInVector);
                
                
                
            }
            else{//north
                
                pos * lastInVector;
                //lastInVector = posvec.back();
                pos* temp = posvec[posvec.size()-1];
                posvec[posvec.size()-1] = NULL;
                posvec.pop_back();
                delete temp;
                vector<pos*>::iterator begin = posvec.begin();
                
                
                x = (*posvec.begin())->x;
                y = (*posvec.begin())->y-10;
                lastInVector = new pos(x,y);
                begin = posvec.insert(begin, lastInVector);
                
            }
        }
        else{
            if(direction > 0){//east
                
                pos * lastInVector;
                //lastInVector = posvec.back();
                pos* temp = posvec[posvec.size()-1];
                posvec[posvec.size()-1] = NULL;
                posvec.pop_back();
                delete temp;
                vector<pos*>::iterator begin = posvec.begin();
                
                
                x = (*posvec.begin())->x+10;
                y = (*posvec.begin())->y;
                lastInVector = new pos(x,y);
                begin = posvec.insert(begin, lastInVector);
            }
            else{//west
                
                pos * lastInVector;
                //lastInVector = posvec.back();
                pos* temp = posvec[posvec.size()-1];
                posvec[posvec.size()-1] = NULL;
                posvec.pop_back();
                delete temp;
                vector<pos*>::iterator begin = posvec.begin();
                
                
                x = (*posvec.begin())->x-10;
                y = (*posvec.begin())->y;
                lastInVector = new pos(x,y);
                begin = posvec.insert(begin, lastInVector);
                
            }
        }
        
    }
    
};

aiSnake snake2(300, 300);

list<Displayable *> dList;           // list of Displayables




/*
 * Initialize X and create a window
 */
void initX(int argc, char *argv[], XInfo &xInfo) {
    //snake2.direction = -snake2.direction;
    //snake2.reverse();
    fruit.theboss = &snake2;
    XSizeHints hints;
    unsigned long white, black;
    
    /*
     * Display opening uses the DISPLAY	environment variable.
     * It can go wrong if DISPLAY isn't set, or you don't have permission.
     */
    xInfo.display = XOpenDisplay( "" );
    if ( !xInfo.display )	{
        error( "Can't open display." );
    }
    
    /*
     * Find out some things about the display you're using.
     */
    xInfo.screen = DefaultScreen( xInfo.display );
    
    white = XWhitePixel( xInfo.display, xInfo.screen );
    black = XBlackPixel( xInfo.display, xInfo.screen );
    
    
    hints.x = 100;
    hints.y = 100;
    hints.width = 800;
    hints.height = 600;
    hints.flags = PPosition | PSize;
    
    xInfo.window = XCreateSimpleWindow(
                                       xInfo.display,				// display where window appears
                                       DefaultRootWindow( xInfo.display ), // window's parent in window tree
                                       hints.x, hints.y,			// upper left corner location
                                       hints.width, hints.height,	// size of the window
                                       Border,						// width of window's border
                                       black,						// window border colour
                                       white);					// window background colour
    
    XSetStandardProperties(
                           xInfo.display,		// display containing the window
                           xInfo.window,		// window whose properties are set
                           "snake,snake!!!",		// window's title
                           "snake",			// icon's title
                           None,				// pixmap for the icon
                           argv, argc,			// applications command line args
                           &hints );
    // size hints for the window
    
    //xInfo.pixmap = XCreatePixmap(xInfo.display, xInfo.window,width, height, 1);
    
    /*
     * Create Graphics Contexts
     */
    int i = 0;
    xInfo.gc[i] = XCreateGC(xInfo.display, xInfo.window, 0, 0);
    XSetForeground(xInfo.display, xInfo.gc[i], BlackPixel(xInfo.display, xInfo.screen));
    XSetBackground(xInfo.display, xInfo.gc[i], WhitePixel(xInfo.display, xInfo.screen));
    XSetFillStyle(xInfo.display, xInfo.gc[i], FillSolid);
    XSetLineAttributes(xInfo.display, xInfo.gc[i],
                       1, LineSolid, CapButt, JoinRound);
    i = 1;
    xInfo.gc[i] = XCreateGC(xInfo.display, xInfo.window, 0, 0);
    XSetForeground(xInfo.display, xInfo.gc[i], WhitePixel(xInfo.display, xInfo.screen));
    XSetBackground(xInfo.display, xInfo.gc[i], BlackPixel(xInfo.display, xInfo.screen));
    XSetFillStyle(xInfo.display, xInfo.gc[i], FillSolid);
    XSetLineAttributes(xInfo.display, xInfo.gc[i],
                       1, LineSolid, CapButt, JoinRound);
    
    int depth = DefaultDepth(xInfo.display, DefaultScreen(xInfo.display));
    xInfo.pixmap = XCreatePixmap(xInfo.display, xInfo.window, hints.width, hints.height, depth);
    xInfo.width = hints.width;
    xInfo.height = hints.height;
    
    XSelectInput(xInfo.display, xInfo.window,
                 ButtonPressMask | KeyPressMask |
                 PointerMotionMask |
                 EnterWindowMask | LeaveWindowMask |
                 StructureNotifyMask);  // for resize events
    
    /*
     * Don't paint the background -- reduce flickering
     */
    
    XSetWindowBackgroundPixmap(xInfo.display, xInfo.window, None);
    
    /*
     * Put the window on the screen.
     */
    
    XMapRaised( xInfo.display, xInfo.window );
    XFlush(xInfo.display);
    //XFillString(xInfo.display, xInfo.window, xInfo.gc[0], 250, 250, "HIIIIIII");
}

/*
 * Function to repaint a display list
 */
void repaint( XInfo &xinfo) {
    list<Displayable *>::const_iterator begin = dList.begin();
    list<Displayable *>::const_iterator end = dList.end();
    
    //XClearWindow( xinfo.display, xinfo.window );
    XFillRectangle(xinfo.display, xinfo.pixmap, xinfo.gc[1],
                   0, 0, xinfo.width, xinfo.height);
    // get height and width of window (might have changed since last repaint)
    
    XWindowAttributes windowInfo;
    XGetWindowAttributes(xinfo.display, xinfo.window, &windowInfo);
    unsigned int height = windowInfo.height;
    unsigned int width = windowInfo.width;
    
    // big black rectangle to clear background
    
    //xinfo.pixmap = XCreatePixmap(
                              //   xinfo.display, xinfo.window,
                            //     width, height, 1);
    
    //XFillRectangle(xinfo.display, xinfo.pixmap,xinfo.gc[0], 0, 0, xinfo.width, xinfo.height);
    
    // draw display list
    int a = score;
    stringstream ss,ss1;
    ss << a;
    ss1<<aiscore;
    string str = ss.str();
    string str2 = ss1.str();
    XDrawString(xinfo.display, xinfo.pixmap, xinfo.gc[0],550, 20, "user score", 10);
    XDrawString(xinfo.display, xinfo.pixmap, xinfo.gc[0],550, 30, str.c_str(), str.length());
    XDrawString(xinfo.display, xinfo.pixmap, xinfo.gc[0],550, 40, "ai score", 8);
    XDrawString(xinfo.display, xinfo.pixmap, xinfo.gc[0],550, 50, str2.c_str(), str2.length());
    XDrawString(xinfo.display, xinfo.pixmap, xinfo.gc[0],550, 70, "Press p to pause", 16);
    XDrawString(xinfo.display, xinfo.pixmap, xinfo.gc[0],550, 90, "Press r to restart", 18);
    if(snake.pausebool){
        XDrawString(xinfo.display, xinfo.pixmap, xinfo.gc[0],550,150, "Paused(press c to continue)", 27);
        
    }
    if(snake.over){
        XDrawString(xinfo.display, xinfo.pixmap, xinfo.gc[0],550,150, "Game Over! Press r to restart", 10);
    }
    while( begin != end ) {
        Displayable *d = *begin;
        d->paint(xinfo);
        begin++;
    }
    //XFillRectangle(xinfo.display, xinfo.pixmap, xinfo.gc[0], 0, 0, width, height);
    
    XCopyArea(xinfo.display, xinfo.pixmap,
              xinfo.window, xinfo.gc[0],
              0, 0, xinfo.width, xinfo.height, // pixmap region to copy
              0, 0);
    
    XFlush( xinfo.display );
}



void handleKeyPress(XInfo &xinfo, XEvent &event) {
    KeySym key;
    char text[BufferSize];
    
    /*
     * Exit when 'q' is typed.
     * This is a simplified approach that does NOT use localization.
     */
    int i = XLookupString(
                          (XKeyEvent *)&event, 	// the keyboard event
                          text, 					// buffer when text will be written
                          BufferSize, 			// size of the text buffer
                          &key, 					// workstation-independent key symbol
                          NULL );					// pointer to a composeStatus structure (unused)
    if ( i == 1) {
        printf("Got key press -- %c\n", text[0]);
        if (text[0] == 'q') {
            cout<<"Terminating normally."<<endl;
            for (int i = 0; i < snake.posvec.size(); i++)
            {
                delete snake.posvec[i];
            }
            for (int i = 0; i < snake2.posvec.size(); i++)
            {
                delete snake2.posvec[i];
            }
            for (int i = 0; i < objVec.size(); i++)
            {
                delete objVec[i]->posi;
                delete objVec[i];
            }
            
            throw (1);
            return;
            
        }
        if(text[0] == 'w'){
            if(snake.upOrNo()){
            }
            else{
                
                
                if(snake.getDirection() > 0){//turn left
                    snake.reverse();
                    
                    snake.setDirection(-snake.getDirection());
                    
                }
                else{
                    snake.reverse(); //turn right
                    
                }
                
            }
        }
        if(text[0] == 's'){
            if(snake.upOrNo()){
            }
            else{
                
                if(snake.getDirection() < 0){
                    snake.reverse();
                    snake.setDirection(-snake.getDirection());
                }
                else{
                    snake.reverse();
                }
            }
        }
        if(text[0] == 'a'){
            if(!snake.upOrNo()){
            }
            else{
                
                if(snake.getDirection() > 0){
                    snake.reverse();
                    snake.setDirection(-snake.getDirection());
                }
                else{
                    snake.reverse();
                }
                
            }
        }
        if(text[0] == 'd'){
            if(!snake.upOrNo()){
            }
            else{
                if(snake.getDirection() < 0){
                    snake.reverse();
                    snake.setDirection(-snake.getDirection());
                }
                else{
                    snake.reverse();
                }
            }
        }
        if(text[0] == 'p'){//pause
            if(snake.getDirection()!=0){
                
                snake.pause(xinfo);
                snake2.pause(xinfo);
            }
        
        }
        if(text[0] == 'c'){
            if(snake.getDirection() == 0){
                snake.resume();
                snake2.resume();
            }
        }
        if(text[0] == 'r'){
            snake = Snake(400, 450);
            snake2 = aiSnake(300,300);
            
            fruit = Fruit();
            fruit.theboss = &snake2;
            score = 0;
            aiscore = 0;
            snake.pausebool = false;
            if(snake.over){
                snake.over = false;
            }
            snake2.pausebool = false;
            if(snake2.over){
                snake2.over = false;
            }
            
        }
        snake.snakeStatus();
        
        
    }
}



void handleAnimation(XInfo &xinfo, int inside,long starting, long time) {
    
    
    
    snake.move(xinfo);
    snake2.move(xinfo);
}

// get microseconds
unsigned long now() {
    timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000000 + tv.tv_usec;
}


void eventLoop(XInfo &xinfo) {
    // Add stuff to paint to the display list
    dList.push_front(&snake);
    dList.push_front(&fruit);
    dList.push_front(&snake2);
    vector<Obstacle*>::iterator iter, end;
    
    for(iter = objVec.begin(), end = objVec.end() ; iter != end; ++iter){
        dList.push_front(*iter);
    }

    
    XEvent event;
    unsigned long lastRepaint = 0;
    int inside = 0;
    long previousTime;
    long currentTime;
    while( true ) {
       
        fruit.alert();
        
        if (XPending(xinfo.display) > 0) {
            XNextEvent( xinfo.display, &event );
            switch( event.type ) {
                case KeyPress:
                    try{
                        handleKeyPress(xinfo, event);}
                    catch(const std::exception& e){
                        return;
                    }
                    break;
                case EnterNotify:
                    inside = 1;
                    break;
                case LeaveNotify:
                    inside = 0;
                    break;
                case NoExpose:
                    continue;
            }
        }
        if(aiscore - score >=200){
            snake2.direction = 0;
            snake.direction = 0;
            XDrawString(xinfo.display, xinfo.window, xinfo.gc[0],300, 380, "YOU LOST", 8);

        
        }
        if(score - aiscore >= 200){
            snake2.direction = 0;
            snake.direction = 0;
            XDrawString(xinfo.display, xinfo.window, xinfo.gc[0],300, 380, "YOU WIN", 7);
        }
        currentTime = now();
        cout<<"current time is"<<currentTime<<endl;
        cout<<"previous time is"<<previousTime<<endl;
        if(currentTime-previousTime >= 100000/speed){//200000/speed){
            handleAnimation(xinfo, inside,currentTime,currentTime);
            previousTime = currentTime;
        }
        usleep(1000000/FPS);
        
        
        repaint(xinfo);
    }
}

void splashScreen(XInfo &xinfo){
    
    XEvent event;
    unsigned long lastRepaint = 0;
    int inside = 0;
    
    while( true ) {
        
        
        int a = score;
        stringstream ss;
        ss << a;
        string str = ss.str();
        
        
        //XDrawString(xinfo.display, xinfo.window, xinfo.gc[0],550, 50, str.c_str(), str.length());
        
        XDrawString(xinfo.display, xinfo.window, xinfo.gc[0],300, 380, "SNAKE GAME", 10);
        
        XDrawString(xinfo.display, xinfo.window, xinfo.gc[0],300, 400, "by Qian Wu", 10);
        XDrawString(xinfo.display, xinfo.window, xinfo.gc[0],300, 420, "ID:20587999", 11);
        XDrawString(xinfo.display, xinfo.window, xinfo.gc[0],300, 440, "PRESS ANY BUTTON TO CONTINUE", 28);
        XDrawString(xinfo.display, xinfo.window, xinfo.gc[0],300, 460, "USE W A S D TO CONTROL DIRECTIONS", 33);
        
        
        
        //cout<<"fruit loc"<<fruit.getX()<<","<<fruit.getY()<<endl;
        if (XPending(xinfo.display) > 0) {
            XNextEvent( xinfo.display, &event );
            //cout << "event.type=" << event.type << "\n";
            switch( event.type ) {
                case KeyPress:
                    return;
                case EnterNotify:
                    inside = 1;
                    break;
                case LeaveNotify:
                    inside = 0;
                    break;
            }
        }
        
        //handleAnimation(xinfo, inside);
        //repaint(xinfo);
    }
    
    
}

/*
 * Start executing here.
 *	 First initialize window.
 *	 Next loop responding to events.
 *	 Exit forcing window manager to clean up - cheesy, but easy.
 */
int main ( int argc, char *argv[] ) {
    //int speed;
    //int fps;
    stringstream ss,ss1;
    ss<<argv[1];
    ss1<<argv[2];
    
    ss>>FPS;
    ss1>>speed;
    cout<<"speed"<<speed<<endl;
    cout<<"FPS"<<FPS<<endl;
    XInfo xInfo;
    initOb(5);
    initX(argc, argv, xInfo);
    splashScreen(xInfo);
    eventLoop(xInfo);
    XCloseDisplay(xInfo.display);
    
    
    
    
}

