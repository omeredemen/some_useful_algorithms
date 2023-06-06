#include <iostream>
#include <vector>
#include <random>
#include <cmath>
#include <algorithm>
#include <map>
#include <SFML/Graphics.hpp>

// Açıyı hesapla (radyan cinsinden)
float calculateAngle(float x, float y)
{
    return std::atan2(y, x);
}

int main()
{
    // Rastgele nokta bulutunu oluştur
    int numPoints = 1000;  // Nokta sayısı
    std::vector<float> xValues(numPoints);
    std::vector<float> yValues(numPoints);
    std::vector<float> zValues(numPoints);

    std::random_device rd;
    std::default_random_engine engine(rd());
    std::uniform_real_distribution<float> distribution(-1.0f, 1.0f);

    for (int i = 0; i < numPoints; ++i)
    {
        xValues[i] = distribution(engine);
        yValues[i] = distribution(engine);
        zValues[i] = distribution(engine);
    }

    // Açıları hesapla
    std::vector<float> angles(numPoints);
    for (int i = 0; i < numPoints; ++i)
    {
        angles[i] = calculateAngle(xValues[i], yValues[i]);
    }

    // Açılara göre histogram hesapla
    int numBins = 10;  // Histogram bin sayısı
    float minAngle = -M_PI;  // Minimum açı (-180 derece)
    float maxAngle = M_PI;  // Maksimum açı (180 derece)

    std::map<int, int> histogram;
    float binSize = (maxAngle - minAngle) / numBins;

    for (float angle : angles)
    {
        int binIndex = static_cast<int>((angle - minAngle) / binSize);
        histogram[binIndex]++;
    }

    // Histogramı görselleştir
    int windowHeight = 400;
    int windowWidth = 800;
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Histogram");

    sf::RectangleShape binShape(sf::Vector2f(windowWidth / numBins, windowHeight));
    binShape.setFillColor(sf::Color::Blue);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);

        for (const auto& entry : histogram)
        {
            int binIndex = entry.first;
            int binCount = entry.second;

            binShape.setPosition(binIndex * (windowWidth / numBins), windowHeight);
            binShape.setSize(sf::Vector2f(windowWidth / numBins, -binCount));
            window.draw(binShape);
        }

        window.display();
    }

    return 0;
}
