float minOfVector(const vector<float>& V) {
    float m = V[0];
    for (int i = 1; i < V.size(); i++) {
        m = min(V[i], m);
    }
    return m;
}

float maxOfVector(const vector<float>& V) {
    float m = V[0];
    for (int i = 1; i < V.size(); i++) {
        m = max(V[i], m);
    }
    return m;
}

namespace SAT {
	bool isPolygonColliding(const Polygon& poly1, const Polygon& poly2) {
		vector<vec2> p1 = poly1.transformPoints();
		vector<vec2> h1 = poly1.transformShapes();
		vector<vec2> p2 = poly2.transformPoints();
		vector<vec2> h2 = poly2.transformShapes();

		for (int i = 0; i < h1.size(); i++) {
			vector<float> f1 = {};
			vector<float> f2 = {};
			for (int j = 0; j < p2.size() + p1.size(); j++) {
				if (j < p1.size()) {
					f1.push_back(p1[j] * h1[i]);
				} else {
					f2.push_back(p2[j - p1.size()] * h1[i]);
				}
			}
			float min1 = minOfVector(f1);
			float max1 = maxOfVector(f1);
			float min2 = minOfVector(f2);
			float max2 = maxOfVector(f2);
			if (min1 > max2 || min2 > max1) {
				return false;
			}
		}
		for (int i = 0; i < h2.size(); i++) {
			vector<float> f1 = {};
			vector<float> f2 = {};
			for (int j = 0; j < p2.size() + p1.size(); j++) {
				if (j < p1.size()) {
					f1.push_back(p1[j] * h2[i]);
				} else {
					f2.push_back(p2[j - p1.size()] * h2[i]);
				}
			}
			float min1 = minOfVector(f1);
			float max1 = maxOfVector(f1);
			float min2 = minOfVector(f2);
			float max2 = maxOfVector(f2);
			if (min1 > max2 || min2 > max1) {
				return false;
			}
		}
		return true;
	}
}; // namespace SAT
