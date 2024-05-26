 
class mat22{
  public:
    //переменные
      vec2 i, j;
    //конструкторы
      mat22() : i(1,0), j(0,1) {}
      mat22(float a, float b, float c, float d){
        i=vec2(a, b);
        j=vec2(c, d);
      }
      mat22(vec2 a, vec2 b){
        i=a;
        j=b;
      }
		//операторы
			vec2 operator*(const vec2& vec) const {
				return vec2(i.x * vec.x + j.x * vec.y, i.y * vec.x + j.y * vec.y);
			}
			mat22 operator*(const mat22& other) const {
				return mat22(
					vec2(i.x * other.i.x + j.x * other.i.y, i.y * other.i.x + j.y * other.i.y),
					vec2(i.x * other.j.x + j.x * other.j.y, i.y * other.j.x + j.y * other.j.y)
				);
			}
};
