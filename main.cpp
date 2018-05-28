
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <numeric>
#include <stdio.h>
#include <stdlib.h>
#include <unordered_map>
#include <getopt.h>
#include <unistd.h>
#include <sstream>
#include <limits>
#include <cstdint>
#include <math.h>
#include <list>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double dl;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

/*********** CODE PARTS ***************/

/* Input:

	Number of test cases is given first:
int TC;
scanf("%d", &TC);
while (TC--) {}

	Read until EOF:
int a, b;
while (scanf("%d %d", &a, &b) != EOF) {}

	Read until the values are 0:
int a, b;
while (scanf("%d %d", &a, &b), (a || b)) {}


    Get lines of integers:
for (std::string line; std::getline(std::cin, line);) {
    //std::cout << line << std::endl;
    std::istringstream is( line );
    int n;
    while( is >> n ) {
        cout << "Int: " << n << endl;
    }
}

*/

/* Output:

	Cases:
cout << "Case #" << i << ": ";

	Precision:
cout.precision(9);
cout << fixed << (double)max_x << endl;

*/


int main() {
    ll X, Y;
    while (cin >> X >> Y) {
        ll N, non_shield_y = Y;
        cin >> N;
        double coeffs_sum = 0; //In the equation d_i = (u_i - l_i)  * F_i * V_x, coeffs_sum would be the sum of (u_i - l_i) * F_i, for all i
        for(int i = 0; i < N; ++i){
            ll l_i, u_i, y_i;
            double f_i, coeff_i;
            cin >> l_i >> u_i;
            cin >> f_i;

            y_i = u_i - l_i;
            non_shield_y -= y_i;
            coeff_i  = f_i * y_i;
            coeffs_sum += coeff_i;
        }
        coeffs_sum += non_shield_y; // in this case f_i is 1, we dont need to multiply the non-shield part of the journey with some f_i
        double V_x = X / coeffs_sum;


        cout.precision(10);
        cout << fixed << V_x << endl;
    }
    return 0;
}