#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define sz(v) (int)v.size()
#define all(v) v.begin(), v.end()
#define filter(v) v.resize(unique(all(v)) - v.begin())
#define dbg(x) "[" #x " = " << (x) << "]"
 
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

template<typename T> bool maximize(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }else return false;
}
template<typename T> bool minimize(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }else return false;
}
template<typename T> T rand(T a, T b) {
    return uniform_int_distribution<T>(a, b)(rng);
}

typedef long long lint;
typedef long double ldble;
 
const int N = 1e7 + 3;

int n, k, x, a, b, c;
int arr[N];

lint totalXor = 0, currentSum = 0;

void process() {
    for(int i = 1; i < k; i++) currentSum ^= arr[i];
    for(int i = k; i <= n; i++) {
        currentSum ^= arr[i];
        totalXor ^= currentSum;
        currentSum ^= arr[i - k + 1];
    }    
    cout << totalXor << endl;
}

void input() {
    cin >> n >> k >> x >> a >> b >> c;

    arr[1] = x;
    for(int i = 2; i <= n; i++) {
        arr[i] = (1LL * a * arr[i - 1] + b) % c;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    #define task "Date_A_Live"
    if(fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    
    int testcase = 1; // cin >> testcase;    
    for(int i = 1; i <= testcase; i++) {
        input();
        process();
    }

    cerr << "Saa, watashtachi no deito hajimemashou" << endl;

    return 0;
}

/*
B####BGGGGP7^^:::::^!J555PPPPPPPGGGGGB###BGGGGGBBGGBGGGGPPPPPPGGGBGGPPPPPPPPPPPPPPPPPPPPP555555555555555555555555YYJ!:...      :!~~77!~~7??JJ?!~!?JYYJ
BBB###BGGGP5~:^^:^~J555PPPPPPPGGGGGB####BGGGGGGBBGGGGGGGGGGGGGGGBBGPPPPPPPPPPPPPPPPPPPPPPPPPPPPP5555555PPPP55555555YYJ~...     .~!~!77~~7JJJJ?!~!?JYYY
BBBBB#BGGGPP!:^:^?5PPPPPPPPPGGGGGB#####BGGGGGGBBGGGGGGGGGGGGGGGB##GGGPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP5555555YY?^.     .~!~!77~~7JJJJ?!~!?YYYY
BBBBBBGGGGGJ^^^!YPPPPPPPGGGGGGGGB#####BGGGGGGB#BBBGGGGGGGGGGGGGBB#GGGGGGGGGPPPPPPPPPPGGPPPPPPPPPPPPPPPPPPPPPPPPPPP5555Y5Y!.     ^!~!77!~!?JJJ?7!!?YYYY
BBBBBBBGGGJ~:^7PPPPGPGGGGGGGGGB###B##GGGBBGBBB#BBBGGGGGGGGGGGGBBB#BGGGGGGGGGGPPPPPPGGGGGGPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP55YJ:    :~!!777~!?JJJJ7!!?YYYY
BBBBBBBGGY~:^JGPGGGGGGGGGGGGBB###BB#BGGGGGBGB##BBBGGGGGGGGGGGBBGB#BGGGGGGBGGGGGGGGGGGGGGGGGPPPPPPPGGGGGPPPPPPPGGPPPPPPPPP55Y~   .~!!777!!7JJJJ?!!?Y5YY
BBBBBBBBP!^^YGGGGGGGGGGGGGGGB##BB#BBBBBBBBBBB##BBBBBGGGGGGGGB#BGB#BGGGGGBBGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGPPPGGGGGGPPPPPPGPP55?. .^!!!77!!7JYJJ?!!?Y555
##BBBBGBY^~5GGGGGGGGGGGGBBBB##BBBBBBBBBBBBBB##BBBBBBGBBBBBGB#BGGB#BGGGGGBBGGGGGG5PGGGGGGGGGGGGGGGGGGGGGBGGGGGGGGGGGGPPGGGY5P5PY. ^!!!77!!7JYYJ?7!?Y555
##BBBBBG7~5GGGGGGGGGGBBBBB###BBBBBBBBBBBBBBB##BBBBBBBGBBBBGBBBGGBB#BGGGBB#BGGGGGYJPGGGGGGGGGGGGGGGGPYPGGBBGGGGGGGGGGGPGPGP?JPPP5^:!!!7?7!7JYYJ?7!?Y555
###BBBBP~5BGGGBBBBBBBBBGB###BBBBBBBBBBBBBBBB##BBBBBBBBBBBBBBBBGBGGBBBGGGG##GGGGYJ7JGGGGGGGGGGGGGGGGPJ75GBBGGGGGGGGGGGGGGGGG7JGPPP7~7!7?7!7?YYYJ?7?555P
####B#B?YBBBBBBBBBBBBBBBB#BBBBBBBBBBBBBBBBBBB#BBBGBBBBBBBBBBBBGBBGBBBBG5PB#BGGGPJJ7PGGGGGGGGGBGGGGGPPJ?PGBBBBPPGGGGBBGGPGGGG!?GPPPJ7777777?JYYJ?775P5P
######GYBBBBBBBBBBBBBBBB#BBBBBBBBBBBBBBBBBBBBBBBBBBBGGBBBBBBGGGGGGGBBGB5YB##GGGPPGYPGGGGGBBGGGGGGGGPPPJYGPB#BGYGGGBBBBGJ5GGGG~?GGGGY777?777JYYY?77Y5PP
#####BGBBBBBBBBBBBBBBBB#BBBBBBBBBBBBBBBBBBBBBBBBBBBBJ5BBBBBBGGPGGGGBBGGGGGB#BGGPPGPPPPGGPG#BGGGGGGGPPPPPGPG#BGGGGGBB#B57?PGBGG:JGGGGY77??77JYYYJ77Y5PP
#####BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBG?5GBBBBGGGYPGGGBBGGGGGB#BGPPPPPPPPGGPPB#BGGPPGGPPPPPPPPB#BGGGGGBB#GJ?5GBGG5:5GGGGJ7??77?JYYJ??JPPP
#######BBBBBBBBBBBBBBBBBBBBBBB##BBBBBBBBBBBBBBBBBBBG7YGGBBBBGGGGGGGGGBGGGGGB#GPPPPPP5PPGPPG###GPPPPGPPPPPPPPB#BGGGGBB##BPJGBBGBJ:PPPGP7???7?JYYJ??YPPP
######BBBBBBBBBBBBBBBBBBBBBB###BBBBBBBBBBBBBB#GGBBBB?JGBGG5YBGGGGGGGGGGPPPPPBBPP5555555PPPPB###BGP5PPPP55555G#BGGGGGB##BGGGBBBGB~~GYGB57??7?JYYY??YPPP
#######BBBBBBBBBBBBBBBBBBBB####BBBBBBBBBBBBBB#P5BBGB55GGGG5:YGPPPPPPPJ7P5P55G#G555555555PP5P###B#BPP55PP5555P#BGGGPGGB##GGGGBBBBG:JGGGG??J??JYYYJ?YPPP
########BBBBBBBBBBBBBBBBBBB####BBBBBBBBBBBBBB#BGBBBGGGGGGP5:.YP55555P7.755555GBP555555555P55G##PPGBBPP55PGP55B#BPPPPPG##BGBGBBBBB5.PGBBP?J??JY5YYJYPPP
########BBBBBBBBBBBBBBBBB#####BBYGBGBBBBBBBBBBBBBBBGGGGPPP5~..YP555557 .?YYY55BG555555555P55PB#GYY55PPP555GGGB##PPPPPPG&BGGGGBBBBB~~BBBBJJJ?JY55YJYPGP
#########BBBBBBBBBBBB#B#######BBJYB5PBBBBBBBBBGBGBBGGPPPP5P!. .Y5YYYY?  .?YY5Y5GG5Y55YYY55P55G#BY55YYY55555PG###GP55PPPBBGGGGBBBBBP:5BBBPJJJJY5P5Y5PGG
#########B###BB######BB########BJ?BYGBBBBBBBBBGGGGGGPPPP555?.  .?YYYYY   .JYY5Y5G555P5555Y5555GBP5YYYYYY555P5PGBBP55P5PPGPPPPGGBBBB!~BBBBJJJJY5P5Y5PGG
###############BB#BBBBB#########57PGBBBBBBBBBBGGGBGBPPPP555J.  .^5555P~::.:J5YYY5P555P55555P555BG5555YYYY5Y5555PGP5P55P5PGPPPPGBBBBP:PBBB5JJJY5PP55PGG
######################B####&##&#G?PBBBBBBBBBBBGGGBPYP5PP5555^^^^:^YYYY!    .?YYYY5P55PPYY555P55PB55P55YY555555555PPPPP555PP5PPGBBBBB~7BBBP???JYY555PPP
############&#B########BB#&&##&&BJGBBBBBBGGGGGGPGBY:5PGGPP55~     :JYJJ.    .7YJY55555Y~Y5YYPP55GG5P5555555555555555PP555PPP55PBBBBBY.GBBG77?JYY55PPGG
###########&&##########B##&&#&&&BGBBBBBBBGGPGGGGYY5.7GPG55YY7      .?YY~      !YYYY5555~.?5Y5PP55PPPP5555555555555555555555PP55BBBBBG:YBBB??JY55PPGGGB
###########&&##PB######BG##&#&&&BBBBBBBBBGGPPGGGY?Y  ?5PY5YYY.      .!YJ.      ^YYYY55Y5. !YY5P555P5P5P5555555555P5555555555PP5GBBBB#~7#BBJJY55PGGGBBB
B#####BG##&&#5GJB######BY##&#&&&#BBBBBBGBBGPPPGGJ~J  :55.J5Y5~      ..~5? ..    :?5YY5P5?  :JYYP5555PPPP555555555PBP55555555PPPG#BBB#Y7#B#PPPPPGBGBBB#
G######YG#&&BGPJB######GP##&&&&&&BGGGGGBB#BPPPPPJ.J   ^5: 7YYY. ....::.:J~.::    .!Y555?5!  .!Y5P5555PGP5555555555B#BP555555P5PG#BBBBB7BB#BPPPPGBBBBB#
G######B##&&##5Y###########&&&&&&BBGGGGGGB#G555GJ.7.   !? :YP5PGBBBBBGGPPPY!:      :?5Y:75:   :?55555PGP5555555555GBBBG55555PGPG###BB#JBB#BPPPPGBBGBB#
######B##&&&##GG###########&&&&&&BGGGGGGGB##P55PY.^: ..!BB#&#BB###BB##J::^!?Y7.      ^J7 ^J:    ^YPY55GG55555555555P5PGGP5555GGGGB####GBB#GPP5PGBBGBB#
#########&&&###############&&&&&&#GGGGGPGG##B555P:...!G############BBB#!     ..       .~. .~:     ~Y5YPG555555555555J55PGP555PGP#BB#######GP55PGBBGGB#
########&&&&################&&&&&&GPGPPPPG#&#B55P! :5#B##BB#PG#BGBBBBBBG                    .      :J55PP555P5555555!.GG55PP55PG######&###P5YYPGBGGGBB
########&&&&################&&&&&&GPPPPPPPB#&&B55J!B&B.G#B##BBG7^Y555PG#.                           .?55JJP5PY5P55555:P#GPP5555PB########B55YYPGGGPPBB
########&&&&#############B###&&&BY5PPPPPPPG####G5PJ~GB ~###BP5YJ77?JYY~^                              ~Y5^7557^YP5555JG#P55PPPP55PB######G5YJYPGGGPPGB
#####&##&&&&#############B#BB##G. !PPPPPPPP###PGP5Y..7~ 7GYPY5J777!7YPG:                               .7Y.:J5!.~Y555PB#P5555PPPGGPG#####P5YJYPGGGPPGB
#####&##&&&&###############BBB#! ^~55555PPPB##P5PP5J. ..  ~5PP5J??????:                                  :^  ~Y! .^?555#P5555J5P########G5YJJYPGGGPPGB
#######&&&&&################BGB~ .:J55555PPG##PP55PP?. .  ..^~^^:...                               .          .~^.  :7PPG55557JP#B######PYJJJYPGGG55GB
#######&&&#################BBBB!  .:555555PP##PP555!5J.  ..                                        .             .   :BGGP5G5!JP#B####B#PYJ?J5PGGP55PB
#####&#&&&#################BBBBP:  .P555555PB#GP55P^.?J. .                                                           7BB555G5!JG######B#GY??J5PGGP55PG
#######&&&########&##########BBBG^  75555555B#G555P~..!J:.                                                          .PBB555G57JG#####BB#GY??J5GGGPYY5G
#####&#&&&########&&#########BBB&#Y: 7P555PPG#B555P!.. :?~. .                                                       !BBB55PP5Y5G#####BBBBJ??J5PGGPYJYP
#####&#&@&########&&#######&#####&&#Y!P55PPPPBB555P?... .^!.                                                       :BBBB55PP555G#####BBBBJ7?J5GGGPYJYP
#######&&&########&&&######&#####&&&&&B5P555PB#PP55Y....  .^:                                       ..            ^GBB#GYYPP5P5G#&###BBBB?7?Y5GGGPYJYP
########&&####&###&@&######&#####&&&&&&P55PPPP#GPP5P~.      .:.                        ... .....   ..            ~B#B##G??PP5P5B#&###BBBG?7?YPGGGPYJYP
########&#########&&&&#####&&####&&&&&&G5PP5PPBGPPPP?~:.      .                                                .7######G??GP5PPB&&##GBBBG?7?YPGGGPYJY5
######B#&###BB#####&@&&####&&####&&&&&@BPP55PPGGPPPPY^~~:.                                                  . :5##&&###GY5BP5PP#&&#GGBBBP77?5GGGGPYJJ5
&#####BB&#B#BB#####&&&&####&&&###&&&@&&#P55PPPPGPPPPP!^^^~:...                                              .?###&&&&&#P5PBP5PP&&##PGBGG577?5GGGGPYJJ5
######BB&#BBBBBB###&&&@&###&@&###&&&&&&&P5PPPPPGPPPPG?^^^^^^^~^:.                                         .~G###&&&&&&#55G#PPPG&&#B5GGGGJ!7?5GGGGPYJJ5
#G#####B##BBBBBBB#&&&&@&&##&&&###&&&&&&&GPPPGPPPPPPPP5^^^^^^^^^~~~^...                                . .^5###&&&&&&&&#55#B5PP#&##55BGGG?!7J5GGGGPYJJ5
BBP####BBBBBBBBBBB#&&&&&@&&&&@&###&&&&&&GPPPBPPPPPPPYG!:^^^^^^^^^^~~~~^^:..                        ... :Y#&&&&&&&&&&&&B5G#BPPP&&#G5PGGGP7!7JPGGBGPYJJ5
B#5G&##BBBBBGGBBGBBB&@@&&&@@@&&###&&&&&&BPPG#PPPPPGPYGY^^^^^^^^^^^~^^^~~~~~~^^:...               .. .:JB##&&&&&&&&&&&&G5B#GPPG&BBP5PGPGY7!7JPGBBGPYJJY
PBBYB###BBBBGGGBGBGGB#&&&&&@&&&###&&&&&&BPPG#PPPPPGGPPP!^^^^^^^^^^^^^^~~^^^~~~~~~~~^^^::.:....    .:JB&#&&&&&&&&&&&&&#PP##PPP#BBG55GGGP?7!7JPGGBGPYJ?Y
~BBGJB##BBBBBGGGGGGGGGGB&&&&&&&&##&&&&&&#PPG#PPPPPPBGPP5^^^^^^^^^^^^^~~~~~~~~~~~~^^~~~~!PBBGP5YJJJ5#&&&&&&&&&&&&&&&&&BPB&#PPGGGGY55GPGY7!!7YGGGGGPYJ?Y
.!BBGJ##BGBBBGGGGGGGGGGGGB#&&@@&B#&&&&&&&PPP&GPPPPPGGPPG?^~~~~^^~^^~~~~~~~~~^^^^~^^~^^7B&#&&&&&&&&&&&&&&&&&&&&&&&&&&&GG#&BPPGGPJYYGPGPJ7!!7YPGGGG5Y??J
..!GBGJB#BGBBGBGGGGGGGGPGGPGB&&&B#&&&&&&&GGP&#PPPPPPGGPP5. ..:^~~~~~~~~~~~~^^^^^^^^~^?#&#&&&&&&&&&&&&&&&&&&&&&&&&&&&#PB&#GPPB57JPGGGPYJ7!!7YPGGGP5J??J
 . ^G#BYG#GGBBBBGGGGGGGGGGPGPGBBB#&&&&&&B!JP&#PPPPPP5^5PPJ       ..:^^~~!~~~~^^^^~^^!?YG#&&&&&&&&&&&&&&&&&&&&&&&&&&&GGB##GPGG7JG#BP55Y?!!!7YPGGGP5J?7?
....^PB#5PBGBBGB##GGGGGGGGGPPGGGGG######5~YG##GPPPPPP.:5PP!             .:^~!!!!~!~!?^~~!B&&&&&&&&&&&&&&&&&&&&&&&&&#GGG&#PP####BGP555J7!!!7YPPGGP5J?7?
~~~~~!5B#BBBGBBGGB##BGGGGGGGGPPPBJY55YP5JYBG##BPPPPPG: :5P5~                 .^^~~~~~~7?~!#&&&&&&&&&&&&&&&&&&&&&&&&BGPG#BGGGYJY555555J?!!!7YPPGGP5J?7?
!!7777!?P###BGBBGGGB###BBGGPPPGP5J777JG5?BBP###PPPP5G7. .YPP:                   ..:^^^^57!7&&&&&&&&&&&&&&&&&&&&&&&#GPPBBGG5?7?Y5PPPP5Y?7!!?YPPPGP5J?7?
JJJJJJJJJ5B#&BGBBBGGGGB####BBG?~:^~!!!~^!PPP###GPPPPP#B5~:?P5:                      .::Y77.Y##&&&&&&&&&&&&&&&&&B5BPGGGGGGP???J5PPPPP5Y?777?5PPPGP5YJ??
55555PP5PP55GBBGGGBBGGGGGGGB5~::~7?7!~:^^5GG##&BPPPPPG###BPGG5:                        ^7~^.BG5GBB&#&&BGBBBG5?!~JY5GPGGGB5JJJJY555555YJ???JY55555YJJJJ
JJJ????????????YGGGGBBBGGGGP^:^7?7!^^:^~~PGPB&&&GPPPPG&######G5!:                      :::!:^#P77?YYJ?77??7!^^!77JYGGGBGB5JJJJJJYYYYYYYYYYYYYYYYYYYYYY
YYYYYYYJJJJJJJJ?JYPGGGBBGGGY:^7J7^^^^JPB##GGB##&BPPPPG#########GG5!:.  .               .:.~#:!&B5YJ5J?77??7!^^^!P#BGPGBGBPY55555555555PPPPPPPPPPPPPPPP
YYYYYYYYYYJJJJJJJJJJYYY555557!YJ^^^^P#####BGB#&##GPPPPB#########B##G5!:.  ...          .7.^##5###BBGGBG5YJJJYPB&&#BGGBBGBP555555555PPPPPPPPPPPPPPPPPPP
55555YYYYYYJJJJJJJJJJJJJJ?JJYJPY!~~P&#####&BG###&BGPPPG###############B5!:............. ?BG##&P#&&&B#&&&&&&&&&&##&BGBBGBB55555555555555PPPPPPPPPPPPPPP
YYYYYYYYYYJJJJJJJJJJJJJJJJJJJYP5JJJ#&&&&####GB#&&#GGGPP###############BB#BY~............^~B###B#&&&B5&&&&&@&&&&###GB#BGBG?JJJJJJJJJJJJJJYYYYYYYYYYYYYY
JJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJYYYP&@@@&&&&&#BB&&##GGPPB#############BGP5G##GY~:.:......:?##&B~?###&&&&&&&&@&&&#&BB##GBB#5JJJJJJJJJJJJJJJJJJJJJJJJJJJJ
JJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJG@@@@@@@@@&&&BB#&#BGGGGB&&&&&&&#####BGGGP5G##BP7:.::::::G##G&P.~G###&&@&&&@@&&&&B#&#BB#&&GJ?JJJJJJJJJJJJJJJJJJJJJJJJJ
JJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJB&&@@@@@@@@@@@&#BB#&BGGGG###&&&&&&&&#######B#####BJ~....:G##^G&J.:?G&##&&&&@@@&&##&&#BB#&&&GYJJJJJJJJJJJJJJJJJJJJJJJJJ
????????????????????????????J?JG&&&&&@@@@@@@@@@@&BB##GGGGB&&&&##&&&&&&&&############P?:.^###.~#&?.~~?#&#&&&&@@@&&&&&BB#&&&&BG5????????????????????????
??????????????????????????????P&&&&&&&&&&&&&&&&&&&&BBBGGBB&&&&&&&##&&&&&&&&#######&##&BJ7##5..5##7^7^^G&&&&&@@@&&&&&BB&&&B#&##5???????????????????????
*/