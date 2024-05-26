namespace SAT{
	class Polygon{
		public:
			//переменные
				vector<vec2> points;
				vector<vec2> shapes;
				vec2 pos;
				float angl;
			//конструкторы
				Polygon(){
					pos = vec2(0,0);
					angl=0;
					points = {};
					shapes = {};
				}
				Polygon(vec2 p, float a, vector<vec2> po){
					points = po;
					pos=p;
					angl=a;
					for(int i=0; i<po.size(); i++){
						shapes.push_back(po[(i+1)%po.size()]-po[i]);
					}
				}
				Polygon(vec2 p, float a, float R, int n){
					points={};
					pos=p;
					angl=a;
					for(int i=0; i<n; i++){
						points.push_back(vf::A2(M_PI*2*(static_cast<float>(i)/n), R));
					}
					for(int i=0; i<points.size(); i++){
						shapes.push_back(points[(i+1)%points.size()]-points[i]);
					}
				}
			//функцыи
				void draw(sf::RenderWindow& window) {
					sf::ConvexShape polygon;
					 polygon.setPointCount(points.size());

					  for (int i = 0; i < points.size(); ++i) {
							polygon.setPoint(i, (vf::A22(angl,1)*points[i]+pos).sfv());
						}

						 polygon.setFillColor(sf::Color::Transparent); // Прозрачный цвет заливки
						 polygon.setOutlineColor(sf::Color::Green);    // Цвет контура
						 polygon.setOutlineThickness(2);
							window.draw(polygon);
				}
				vector<vec2> transformPoints() const {
					vector<vec2> r;
					r.reserve(points.size());  // Резервируем место для точек
					mat22 transformationMatrix = vf::A22(angl, 1);
					for (const auto& point : points) {
						r.push_back(transformationMatrix * point + pos);
					}
					return r;
				}
				vector<vec2> transformShapes() const {
					vector<vec2> r;
					r.reserve(shapes.size());  // Резервируем место для форм
					mat22 transformationMatrix = vf::A22(angl+M_PI/2, 1);
					for (const auto& shape : shapes) {
						r.push_back(transformationMatrix * shape);
					}
					return r;
				}
	};
};
