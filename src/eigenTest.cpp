#include <Eigen/Dense>
#include <Eigen/Core>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    Eigen::Matrix3d a;
    a << 1, 2, 3, 4, 5, 6, 7, 8, 9;
    cout << a << endl;
    return 0;
}
