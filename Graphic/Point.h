#ifndef POINT_H
#define POINT_H


class Point
{
    public:
        Point(int xpos,int ypos);
        virtual ~Point();
        int& getX()
        {
            return xPos;
        }
        int& getY()
        {
            return yPos;
        }
    protected:
    private:
        int xPos,yPos;

};


#endif // POINT_H
