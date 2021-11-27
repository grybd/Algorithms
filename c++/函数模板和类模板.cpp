//模板函数的语法
template <typename T> void Swap(T&a,T&b){
  T temp = a;
  a = b;
  b = temp;
}

template <typename T1,typename T2>
class Point{
public:
  Point(T1 x, T2 y):m_x(x),m_y(y){}
public:
  T1 getX() const;
  void setX(T1 x);
  T2 getY() const;
  void setY(T2 y);
private:
  T1 m_x;
  T2 m_y;
};

template <typename T1,typename T2>
T1 Point<T1,T2>::getX() const{
  return m_x;
}
