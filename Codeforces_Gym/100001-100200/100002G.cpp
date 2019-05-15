#include<bits/stdc++.h>
using namespace std;

#define ENDL "\n"
using LD = long double;
const int MX = 105;
const long double eps = 1e-5, PI_2 = acosl(0);

struct Vector {
    LD x, y, z;
    Vector(LD x = 0, LD y = 0, LD z = 0) : x(x), y(y), z(z) {}
    Vector operator + (Vector a) {return Vector(x + a.x, y + a.y, z + a.z);}
    Vector operator - (Vector a) {return Vector(x - a.x, y - a.y, z - a.z);}
    Vector operator * (long double a) {return Vector(x * a, y * a, z * a);}
    Vector operator / (long double a) {return Vector(x / a, y / a, z / a);}
    Vector operator ^ (Vector a) {
        return Vector(
            y * a.z - z * a.y, 
            z * a.x - x * a.z, 
            x * a.y - y * a.x
        );
    }
    LD operator * (const Vector &v) const {
        return x * v.x + y * v.y + z * v.z;
    }
    LD normal() const {return x * x + y * y + z * z;}
    LD length() const {return sqrtl(normal());}
    Vector identity() {return (*this) / length();}
};
using Circle = pair<Vector, LD>;

int N;
vector<int> ans;
Circle circles[MX];

auto sqr = [](LD val){return val * val;};

vector<int> check(Vector n) {
    Vector v = n.identity();
    vector<int> ans;
    for(int i = 1; i <= N; i++) {
        long double length = circles[i].first * v;
        if(circles[i].first.normal() - sqr(length) < sqr(circles[i].second) + eps)
            ans.push_back(i);
    }
    return ans;
}
vector<int> solve(Circle A, Circle B) {
    LD cosAOB, cosAOP, cosBOP, sinAOB, sinAOP, sinBOP, cosH, sinH;
    cosAOB = A.first * B.first / (A.first.length() * B.first.length());
    if(cosAOB > 1 - eps) return {};
    sinAOB = sqrtl(1 - cosAOB * cosAOB);
    sinAOP = A.second / A.first.length();
    cosAOP = sqrtl(1 - sinAOP * sinAOP);
    sinBOP = B.second / B.first.length();
    cosBOP = sqrtl(1 - sinBOP * sinBOP);
    cosH = sqrtl(sqr(cosAOP) + sqr(cosBOP) - 2 * cosAOP * cosBOP * cosAOB) / sinAOB;
    sinH = sqrtl(1 - cosH * cosH);
    if(cosH > 1 + eps) return {};
    LD x = cosH * sqrtl(1 - sqr(cosBOP / cosH)) / (sinAOB * A.first.length());
    LD y = cosH * sqrtl(1 - sqr(cosAOP / cosH)) / (sinAOB * B.first.length());
    Vector vec0 = A.first * x + B.first * y;
    if(cosH > 1 - eps)
        return check(vec0);
    Vector vec1 = (A.first ^ B.first).identity() * sinH;
    vector<int> ans1 = check(vec0 + vec1), ans2 = check(vec0 - vec1);
    return ans1.size() > ans2.size() ? ans1 : ans2;
}

int main() {
    ifstream cin("ghosts.in");
    ofstream cout("ghosts.out");
    cin >> N;
    for(int i = 1; i <= N; i++) {
        int x, y, z;
        cin >> x >> y >> z >> circles[i].second;
        circles[i].first = Vector(x, y, z);
    }
    for(int i = 1; i <= N; i++) {
        vector<int> curans = check(circles[i].first);
        if(curans.size() > ans.size())
            ans = curans;
    }
    for(int i = 1; i < N; i++)
        for(int j = i + 1; j <= N; j++) {
            vector<int> curans = solve(circles[i], circles[j]);
            if(curans.size() > ans.size())
                ans = curans;
        }
    cout << ans.size() << ENDL;
    for(int &i : ans)
        cout << i << ' ';
    return 0;
}
