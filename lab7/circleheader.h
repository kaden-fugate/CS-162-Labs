#ifndef CIRCLEHEADER_H
#define CIRCLEHEADER_H

class Circle : public Shape{

    private:

        float radius;

    public:

        Circle(float, std::string);
        //~Circle();
        float area();

};

#endif