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

const string directory = "D:\\code\\shidou\\sinh_test_cho_themis\\";
const string filename = "NGOCHUE\\";

namespace solution {
    // Paste your global declarations here

    template<typename T> bool minimize(T &res, const T &val) { if (res > val){ res = val; return true; }; return false; }

    const long long INF = 1e18 + 3;

    int m, n;
    int val[50], pw3[50], curmask[50];
    long long f[50][60012];
    bool good[50][50];
    string s;

    bool isDigit(char c) {
        return ('0' <= c && c <= '9');
    }

    //

    void solve(int testcase) {
        string input_file = directory + filename + "TEST" + convert(testcase) + "\\" + "NGOCHUE.INP";
        string output_file = directory + filename + "TEST" + convert(testcase) + "\\" + "NGOCHUE.OUT";

        freopen(input_file.c_str(), "r", stdin);
        freopen(output_file.c_str(), "w", stdout);

        // Paste your code here

         cin >> m >> n;

    for(int i = 0; i < m; i++)
        cin >> val[i];

    getline(cin, s);

    for(int i = 0; i < n; i++) {
        getline(cin, s);
        int cur = 0;
        for(char c : s) {
            if(isDigit(c))
                cur *= 10, cur += c - '0';
            else {
                if(cur) {
                    // cout << cur << " ";
                    good[i][--cur] = true;
                }
                cur = 0;
            }
        }
        if(cur) {
            // cout << cur << " ";
            good[i][--cur] = true;
        }
        // cout << el;
    }

    pw3[0] = 1;
    for(int i = 1; i <= n; i++)
        pw3[i] = pw3[i - 1] * 3;

    for(int i = 0; i < m; i++) {
        for(int mask = 0; mask < pw3[n]; mask++) {
            f[i][mask] = INF;
        }
    }

    int fir = 0;
    for(int i = 0; i < n; i++) {
        if(good[i][0]) fir += pw3[i];
    }

    f[0][fir] = val[0];
    f[0][0] = 0;


    for(int i = 1; i < m; i++) {
        for(int mask = 0; mask < pw3[n]; mask++) {
            f[i][mask] = f[i - 1][mask];

            int cur = mask;

            for(int j = n - 1; j >= 0; j--) {
                for(int ter = 2; ter >= 0; ter--) {
                    if(cur - pw3[j] * ter >= 0) {
                        cur -= pw3[j] * ter;
                        curmask[j] = ter;
                        break;
                    }
                }
            }

            bool isOn = true;

            for(int j = 0; j < n; j++) {
                if(good[j][i]) {
                    curmask[j]--;
                    if(curmask[j] < 0) {
                        isOn = false;
                        break;
                    }
                }
            }

            if(isOn) {
                int prevmask = 0;
                for(int j = 0; j < n; j++)
                    prevmask += pw3[j] * curmask[j];

                minimize(f[i][mask], f[i - 1][prevmask] + val[i]);
            }
        }
    }

    cout << (f[m - 1][pw3[n] - 1] >= INF ? -1 : f[m - 1][pw3[n] - 1]) << '\n';

        //

        fclose(stdin);
        fclose(stdout);
    }
};

void generate_input(int id) {
    ofstream input(directory + filename + "TEST" + convert(id) + "\\" + "NGOCHUE.INP");

    // Generate test
    int m = 30, n = 10;
    input << m << " " << n << endl;
    for(int i = 1; i <= m; i++) input << limit_random(1000000000) << " \n"[i == m];
    for(int i = 1; i <= n; i++) {
        int k = limit_random(m);
        for(int j = 1; j <= k; j++) input << limit_random(m) << " \n"[j == k];
    }
}

void generate_output(int id) {
    ofstream output(directory + filename + "TEST" + convert(id) + "\\" + "NGOCHUE.OUT");
    solution::solve(id);
}

int main() {
//    if(_mkdir((directory + filename).c_str())) {
//        cerr << "Already exists, please change the filename" << endl;
//        return 0;
//    }

    int numTestCase = 30; // Edit the number of testcase
    for(int testcase = 21; testcase <= numTestCase; testcase++) {
        _mkdir((directory + filename + "TEST" + convert(testcase)).c_str());
        generate_input(testcase);
        generate_output(testcase);
    }

    cerr << "Test generation finished, goodbye" << endl;
    cerr << "Time elapsed: " << (1000.0 * clock() / CLOCKS_PER_SEC) << "ms" << endl;

    return 0;
}
