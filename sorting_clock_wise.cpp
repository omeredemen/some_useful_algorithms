#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

struct Point {
    int x;
    int y;
};

// İki nokta arasındaki açıyı hesaplar
double calculateAngle(Point center, Point point) {
    double angle = atan2(point.x - center.x, point.y - center.y);
    return angle < 0 ? angle + 2 * M_PI : angle;
}

// Saat yönünün tersine göre noktaları sıralar
void sortPointsClockwise(std::vector<Point>& points) {
    // Noktaların merkezini bul
    Point center = {0, 0};
    for (const auto& point : points) {
        center.x += point.x;
        center.y += point.y;
    }
    center.x /= points.size();
    center.y /= points.size();

    // Noktaları merkeze olan açılara göre sırala
    std::sort(points.begin(), points.end(), [center](const Point& p1, const Point& p2) {
        return calculateAngle(center, p1) < calculateAngle(center, p2);
    });
}

int main() {
    // Örnek nokta listesi
    std::vector<Point> points = {{1, 1}, {1, -1}, {1, 0}, {0, -1}, {-1, 0}, {-1, -1} , {0, 1}, {-1 ,1}};

    // Noktaları saat yönünün tersine sırala
    sortPointsClockwise(points);

    // Sıralanmış noktaları ekrana yazdır
    for (const auto& point : points) {
        std::cout << "(" << point.x << ", " << point.y << ")" << std::endl;
    }

    return 0;
}
