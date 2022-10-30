#include <iostream>
#include <tuple>
#include <vector>
typedef std::tuple<double, double> point;
typedef std::vector<point> points;

struct Fraction{
    double numerator;
    double denominator;
};

point intersectingLines(point &A, point &B, point &C, point &D)
{
    // Line AB represented as a1x + b1y = c1
    double a1 = std::get<1>(B) - std::get<1>(A);
    double b1 = std::get<0>(A) - std::get<0>(B);
    double c1 = a1*(std::get<0>(A)) + b1*(std::get<1>(A));
 
    // Line CD represented as a2x + b2y = c2
    double a2 = std::get<1>(D) - std::get<1>(C);
    double b2 = std::get<0>(C) - std::get<0>(D);
    double c2 = a2*(std::get<0>(C))+ b2*(std::get<1>(C));
 
    double determinant = a1*b2 - a2*b1;
 
    if (determinant == 0){
        // The lines are parallel. This is simplified
        // by returning a pair of FLT_MAX
        return point(-1,-1);
    }
    double x = (b2*c1 - b1*c2)/determinant;
    double y = (a1*c2 - a2*c1)/determinant;
    return point(x, y);
    
}

// This function determines if the points lie on the same cirumference.
bool circumferencePoints(points &circlePoints){
    /*
    *  Step 01: Determine the mid point between points as they appear in the vector DONE
    *  Mid point (x,y): ((x1+x2) / 2, (y1+y2) /2)
    *  Step 02: Determine gradient between points as they appear in the vector      DONE
    *  Slope y/x: (y2-y1) / (x2 - x1)
    *  Step 03: Find the perpendicular gradient                                     IN PROGRESS
    *  Perp: Find the recipricol and mulitiply by - 1
    *  Step 04: Find additional point for perpendicular point
    *  Step 05: Determine if adjacent pairs of points intersect
    */

    std::cout << "--- Algorithm Starting ---\n";
    points midpoints;
    points intersectPoints;
    points truth;
    std::vector<double> m;
    std::vector<Fraction> slopes;

    // Step 01
    for(auto it = circlePoints.begin(); it != circlePoints.end(); it++){
        double x1 = std::get<0>(*it);
        double y1 = std::get<1>(*it);
        it++;
        double x2 = std::get<0>(*it);
        double y2 = std::get<1>(*it);
        it--;

        point midpoint = point((x1 + x2) / 2, (y1 + y2) /2);
        midpoints.push_back(midpoint);
    }
    // Step 02
    for(auto it = midpoints.begin(); it != midpoints.end(); it++){
        double x1 = std::get<0>(*it);
        double y1 = std::get<1>(*it);
        it++;
        double x2 = std::get<0>(*it);
        double y2 = std::get<1>(*it);
        it--;

        Fraction fraction;
        fraction.numerator = (y2-y1);
        fraction.denominator = (x2 - x1);

        slopes.push_back(fraction);
    }
    // Step 03
    for (auto it = slopes.begin(); it != slopes.end(); it++){
        m.push_back(-1 * (it->denominator / it->numerator));
    }
    // Step 04
    auto itmp = midpoints.begin();
    auto itm = m.begin();

    while(itmp != midpoints.end() || itm != m.end()){
        double b = (*itm * (-1 * std::get<0>(*itmp))) + std::get<1>(*itmp);
        double x = 10;
        double y = (*itm * x) + b;
        intersectPoints.push_back(point(x,y));
        ++itmp;
        ++itm;
    }
    // Step 05
    itmp = midpoints.begin();
    auto itin = intersectPoints.begin();
    int size = midpoints.size();
    int i = 0;

    while(i < size - 1){
        point A = *itmp;
        point B = *itin;
        ++itmp;
        ++itin;
        point C = *itmp;
        point D = *itin;
        --itmp;
        --itin;
        truth.push_back(intersectingLines(A, B, C, D));
        ++i;
        ++itmp;
        ++itin;
    }

    double x = -1;
    double y = -1;

    for(auto it = truth.begin(); it != truth.end(); it++){
        if(it == truth.begin()){
            x = std::get<0>(*it);
            y = std::get<1>(*it);
        }

        std::cout << std::get<0>(*it);
        if((std::get<0>(*it) != x) | (std::get<1>(*it) != y)){
            std::cout << "--- Algorithm Ending --- \n";
            //return false;
        }
    }

    std::cout << "--- Algorithm Ending ---\n";

    return true;
}

int main(){
    std::cout << "--- Program Starting ---\n";

    points circlePoints;
    circlePoints.push_back(std::tuple<double, double>(-1.2,1.6));
    circlePoints.push_back(std::tuple<double, double>(-1.85, 0.86));
    circlePoints.push_back(std::tuple<double, double>(1.41, 1.418));
    circlePoints.push_back(std::tuple<double, double>(0.2, 1.99));
    circlePoints.push_back(std::tuple<double, double>(-1.968, 0.356));

    for(auto i = circlePoints.begin(); i != circlePoints.end(); i++){
        std::cout << std::get<0>(*i) << ", ";
        std::cout << std::get<1>(*i) << "\n ";
    }

    if(circumferencePoints(circlePoints)){
        std::cout << "The points form a circle.\n";
    }else{
        std::cout << "The points do not form a circle\n";
    }
    
    std::cout << "--- Program Ending ---\n";
    
    return 0;
}