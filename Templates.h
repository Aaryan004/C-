template <typename T,typename V>
class Pair{
private:
    T x;
    V y;
public:
    void setx(T x){
    this->x=x;
    }
    void sety(V y){
    this->y=y;
    }
    T getx(){
    return x;
    }
    V gety(){
    return y;
    }

};
