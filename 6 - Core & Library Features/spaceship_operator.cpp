// Run with in cl
/*
cl.exe spaceship_operator.cpp /std:c++latest /EHsc
*/

#include <compare>
#include <iostream>

class Rectangle
{
 public:
    Rectangle(int x, int y) : m_x(x), m_y(y)
    {
        // Do nothing
    }

    int GetArea() const
    {
        return m_x * m_y;
    }

    std::strong_ordering operator<=>(const Rectangle& r) const
    {
        if (GetArea() == r.GetArea() && m_x <=> r.m_x == 0 && m_y <=> r.m_y == 0)
        {
            return std::strong_ordering::equal;
        }
        
        if (m_x <=> r.m_x == 0)
        {
            return m_y <=> r.m_y;
        } 
        
        return m_x <=> r.m_x;
    }    

    // std::weak_ordering operator<=>(const Rectangle& r) const
    // {
    //     if (GetArea() == r.GetArea())
    //     {
    //         return std::weak_ordering::equivalent;
    //     }

    //     return GetArea() > r.GetArea();
    // }

 private:
    int m_x, m_y;
};

int main()
{
    Rectangle r1(8, 2);
    Rectangle r2(4, 4);
    Rectangle r3(2, 2);
    Rectangle r4(8, 8);

    std::cout << std::boolalpha << (r1<=>r2 == 0) << '\n';
    std::cout << std::boolalpha << (r1<=>r3 > 0) << '\n';
    std::cout << std::boolalpha << (r1<=>r4 < 0) << '\n';

    return 0;
}