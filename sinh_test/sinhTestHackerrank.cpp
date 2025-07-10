#include <bits/stdc++.h>
#include <direct.h>

#define endl '\n'

using namespace std;

namespace useful_tools {
    const int nine = 1e9;
    const int six = 1e6;
    const int five = 1e5;
    const int three = 1e3;

    string convert(int id) {
        if(0 <= id && id <= 9)
            return "0" + to_string(id);
        else return to_string(id);
    }

} using namespace useful_tools;

namespace random_tools {
    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

    template<typename T> int_random(T a, T b) {
        return uniform_int_distribution<T>(a, b)(rng);
    }

    template<typename T> limit_random(T a) {
        return uniform_int_distribution<T>(1, a)(rng);
    }

    template<typename T> real_random(T a, T b) {
        return uniform_real_distribution<T>(a, b)(rng);
    }

} using namespace random_tools;

const string directory = "D:\\code\\shidou\\sinh_test_cho_hackerrank\\";
const string filename = "DAYDEN\\";

namespace solution {
    // Paste your global declarations here

    const int N = 1e5 + 3;

    int n, m, q, k;
    int x[N];

    //

    void solve(int testcase) {
        string input_file = directory + filename + "input\\" + "input" + convert(testcase) + ".txt";
        string output_file = directory + filename + "output\\" + "output" + convert(testcase) + ".txt";

        freopen(input_file.c_str(), "r", stdin);
        freopen(output_file.c_str(), "w", stdout);

        // Paste your code here

        cin >> n >> m >> q >> k;

        for(int i = 1; i <= m; i++) {
            cin >> x[i];
        }

        sort(x + 1, x + 1 + m);

        while(q--) {
            int p; cin >> p;

            auto l = lower_bound(x + 1, x + 1 + m, p - k);
            auto r = upper_bound(x + 1, x + 1 + m, p + k);
            int total = r - l;

            cout << ((total & 1) ? "D" : "V") << endl;
        }

        //

        fclose(stdin);
        fclose(stdout);
    }
};

void generate_input(int id) {
    ofstream input(directory + filename + "input\\" + "input" + convert(id) + ".txt");

    // Generate test
    int n = limit_random(nine), m = limit_random(five), q = limit_random(five), k = int_random(0, n);
    input << n << " " << m << " " << q << " " << k << endl;
    for(int i = 1; i <= m; i++) input << limit_random(n) << " \n"[i == m];
    for(int i = 1; i <= q; i++) input << limit_random(n) << " \n"[i == q];
}

void generate_output(int id) {
    ofstream output(directory + filename + "output\\" + "output" + convert(id) + ".txt");
    solution::solve(id);
}

int main() {
    if(_mkdir((directory + filename).c_str())) {
        cerr << "Already exists, please change the filename" << endl;
        return 0;
    }

    _mkdir((directory + filename + "input").c_str());
    _mkdir((directory + filename + "output").c_str());

    int numTestCase = 30; // Edit the number of testcase
    for(int testcase = 1; testcase <= numTestCase; testcase++) {
        generate_input(testcase);
        generate_output(testcase);
    }

    cerr << "Test generation finished, goodbye" << endl;
    cerr << "Time elapsed: " << (1000.0 * clock() / CLOCKS_PER_SEC) << "ms" << endl;

    return 0;
}
