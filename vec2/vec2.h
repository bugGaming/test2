/*\
|*|это класс вектора
\*/

class vec2{
	public:
		//переменные
			float x, y;
		//конструкторы
			vec2() : x(0), y(0) {}
			vec2(float X, float Y) : x(X), y(Y) {}
		//операторы
			vec2 operator+(const vec2& ohr) const {
				return vec2(x+ohr.x, y+ohr.y);
			}
			vec2 operator-(const vec2& ohr) const {
				return vec2(x-ohr.x, y-ohr.y);
			}
			vec2 operator*(float f) const {
				return vec2(x*f, y*f);
			}
			vec2 operator/(float f) const {
				return vec2(x/f, y/f);
			}
			float operator*(const vec2& ohr) const {
				return x*ohr.x+y*ohr.y;
			}
		//функцыи
			vec2 xy(){return vec2(x,y);}
			vec2 yx(){return vec2(y,x);}

			float length(){
				return sqrt(x * x + y * y);
			}
			vec2 norm(){
				return *this/length();
			}
			sf::Vector2f sfv(){
				return sf::Vector2f(x,y);
			}
			sf::Vector2i sfi(){
				return sf::Vector2i(x,y);
			}
			void setSFV(sf::Vector2f v){
				x=v.x;
				y=v.y;
			}
			void setSFI(sf::Vector2i v){
				x=v.x;
				y=v.y;
			}
};
