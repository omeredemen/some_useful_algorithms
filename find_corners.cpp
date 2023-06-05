#include <iostream>
#include <vector>

struct Point {
    int x;
    int y;
};

std::vector<Point> findCornerPoints(const std::vector<Point>& points) {
    std::vector<Point> cornerPoints;

    if (points.empty()) {
        return cornerPoints;
    }

    int minX = points[0].x;
    int minY = points[0].y;
    int maxX = points[0].x;
    int maxY = points[0].y;

    for (const auto& point : points) {
        if (point.x < minX) {
            minX = point.x;
        }
        if (point.y < minY) {
            minY = point.y;
        }
        if (point.x > maxX) {
            maxX = point.x;
        }
        if (point.y > maxY) {
            maxY = point.y;
        }
    }

    cornerPoints.push_back({minX, minY});
    cornerPoints.push_back({minX, maxY});
    cornerPoints.push_back({maxX, minY});
    cornerPoints.push_back({maxX, maxY});

    for (const auto& point : points) {
        if (point.x == minX && point.y != minY && point.y != maxY) {
            cornerPoints.push_back(point);
        }
        if (point.x == maxX && point.y != minY && point.y != maxY) {
            cornerPoints.push_back(point);
        }
        if (point.y == minY && point.x != minX && point.x != maxX) {
            cornerPoints.push_back(point);
        }
        if (point.y == maxY && point.x != minX && point.x != maxX) {
            cornerPoints.push_back(point);
        }
    }

    return cornerPoints;
}

int main() {
    std::vector<Point> points = {{0, 0}, {1, 1}, {1, -1}, 
                                {1, 0}, {0, -1}, {-1, 0}, 
                                {-1, -1}, {0, 1}, {-1 ,1},
                                {1, 2}, {0,2}};

    std::vector<Point> cornerPoints = findCornerPoints(points);

    for (const auto& point : cornerPoints) {
        std::cout << "(" << point.x << ", " << point.y << ")" << std::endl;
    }

    return 0;
}
