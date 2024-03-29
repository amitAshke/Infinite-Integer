//10.11.18
#include <iostream>
#include <string>
#include "LargeIntegers.h"
#include <limits.h>

int main() {
    int counter = 0;
    try {
        //**************************** 1 ************************
        InfInt x("-1928471213929123");
        InfInt y("21847300019283291032487");
        if (x * y == InfInt("-42131889189261000583868776510708418901")) {
            counter++;
            cout << "Test 1 : Passed" << endl;
        } else {
            cout << "Test 1 : failed " << endl;
        }
        //**************************** 2 ************************
        x = InfInt("-94128312832331823812381238455514343123");
        y = InfInt("33471910001238347191237456190198776629419213841710");
        if ((x + y == InfInt("33471910001144218878405124366386395390963699498587"))
            && (x - y == InfInt("-33471910001332475504069788014011157867874728184833"))) {
            counter++;
            cout << "Test 2 : Passed" << endl;
        } else {
            cout << "Test 2 : failed " << endl;
        }
        //**************************** 3 ************************
        if (y / x == InfInt("-355598745946") && x / y == InfInt(0)) {
            counter++;
            cout << "Test 3 : Passed" << endl;
        } else {
            cout << "Test 3 : failed " << endl;
        }
        //**************************** 4 **************************
        x = InfInt("-100020330492482348234723472");
        y = InfInt(1);
        if (x / x == y && x / y == x && y / y == y) {
            counter++;
            cout << "Test 4 : Passed" << endl;
        } else {
            cout << "Test 4 : failed " << endl;
        }
        //**************************** 5 **************************
        if (++x == InfInt("-100020330492482348234723471") && ++x > x++) {
            counter++;
            cout << "Test 5 : Passed" << endl;
        } else {
            cout << "Test 5 : failed " << endl;
        }
        //**************************** 6 **************************
        x = InfInt("9192391235383838383838262811010049484847574832929191238374656123443");
        y = InfInt(2);
        if (x % y == 1) {
            counter++;
            cout << "Test 6 : Passed" << endl;
        } else {
            cout << "Test 6 : failed " << endl;
        }
        //**************************** 7 **************************
        InfInt z = InfInt("83388338383737332828");
        if (x % z == InfInt("34722825372841036331")) {
            counter++;
            cout << "Test 7 : Passed" << endl;
        } else {
            cout << "Test 7 : failed " << endl;
        }
        //**************************** 8 **************************
        if (((x - (x % z)) % z) == InfInt("0")) {
            counter++;
            cout << "Test 8 : Passed" << endl;
        } else {
            cout << "Test 8 : failed " << endl;
        }
        //**************************** 9 **************************
        x = InfInt("-345953");
        z = InfInt("14");
        if (x % z == InfInt("-13")) {
            counter++;
            cout << "Test 9 : Passed" << endl;
        } else {
            cout << "Test 9 : failed " << endl;
        }
        //**************************** 10 **************************
        y = InfInt("345953");
        z = InfInt("14");
        if (y % z == InfInt("13")) {
            counter++;
            cout << "Test 10: Passed" << endl;
        } else {
            cout << "Test 10: failed " << endl;
        }
        //**************************** 11 **************************
        x = InfInt("3432");
        int p = (int) x;
        if (p == 3432) {
            counter++;
            cout << "Test 11: Passed" << endl;
        } else {
            cout << "Test 11: failed " << endl;
        }
        //**************************** 12 **************************
        x = InfInt("9353882348234823848234823483248238483123912394");
        p = (int) x;
        if (p == INT_MAX) {
            counter++;
            cout << "Test 12: Passed" << endl;
        } else {
            cout << "Test 12: failed " << endl;
        }
        //**************************** 13 **************************
        x = InfInt("-12313139129319394948234727347737274912312391239128747127");
        p = (int) x;
        if (p == INT_MIN) {
            counter++;
            cout << "Test 13: Passed" << endl;
        } else {
            cout << "Test 13: failed " << endl;
        }
        //**************************** 14 **************************
        x = InfInt("123129328248411233900004128340");
        y = InfInt("0");
        if (x * y == y) {
            counter++;
            cout << "Test 14: Passed" << endl;
        } else {
            cout << "Test 14: failed " << endl;
        }
        //**************************** 15 **************************
        if (x + y == x) {
            counter++;
            cout << "Test 15: Passed" << endl;
        } else {
            cout << "Test 15: failed " << endl;
        }
        //**************************** 16 **************************
        if (x - y == x) {
            counter++;
            cout << "Test 16: Passed" << endl;
        } else {
            cout << "Test 16: failed " << endl;
        }
        //**************************** 17 **************************
        x = InfInt("827463125379901777777777771923841200001237123548192734");
        y = InfInt("0");
        if (x - x == y) {
            counter++;
            cout << "Test 17: Passed" << endl;
        } else {
            cout << "Test 17: failed " << endl;
        }
        //**************************** 18 **************************
        y = InfInt("2");
        if (x + x == (x * y)) {
            counter++;
            cout << "Test 18: Passed" << endl;
        } else {
            cout << "Test 18: failed " << endl;
        }
        //**************************** 19 **************************
        x = InfInt("-391111111111111111113838381901032139243");
        y = InfInt("0");
        if (x - x == y) {
            counter++;
            cout << "Test 19: Passed" << endl;
        } else {
            cout << "Test 19: failed " << endl;
        }
        //**************************** 20 **************************
        x = InfInt("-9231838881238321238283128318238123823812381238923929238923404040191304912388130124");
        y = InfInt("-1");
        if (x / y == (x * y)) {
            counter++;
            cout << "Test 20: Passed" << endl;
        } else {
            cout << "Test 20: failed " << endl;
        }
        //**************************** 21 **************************
        y = InfInt("4");
        if (x / y == InfInt("-2307959720309580309570782079559530955953095309730982309730851010047826228097032531")) {
            counter++;
            cout << "Test 21: Passed" << endl;
        } else {
            cout << "Test 21: failed " << endl;
        }
        //**************************** 22 **************************
        y = InfInt("9192903101123334428342834724373462364");
        if (x * y ==
            InfInt("-84867400280406737602417813452625617702131831330981459573483241438740623663018873045450620881448533588762909737648653136")) {
            counter++;
            cout << "Test 22: Passed" << endl;
        } else {
            cout << "Test 22: failed " << endl;
        }
        //**************************** 23 **************************
        x = InfInt("347419203810123817231201231248113");
        if (x >= x) {
            counter++;
            cout << "Test 23: Passed" << endl;
        } else {
            cout << "Test 23: failed " << endl;
        }
        //**************************** 24 **************************
        x = InfInt("347419203810123817231201231248113");
        if (x <= x) {
            counter++;
            cout << "Test 24: Passed" << endl;
        } else {
            cout << "Test 24: failed " << endl;
        }
        //**************************** 25 **************************
        x = InfInt("132021293192391239940102349499124991241924912491291230");
        y = InfInt("119999999999999999999999999999999999999999999999999999");
        z = InfInt("-34300404000000000000000000000000001239123193919239948214818482413230");
        if (y < x && x > y) {
            counter++;
            cout << "Test 25: Passed" << endl;
        } else {
            cout << "Test 25: failed " << endl;
        }
        //**************************** 26 **************************
        if (z < y && z < x) {
            counter++;
            cout << "Test 26: Passed" << endl;
        } else {
            cout << "Test 26: failed " << endl;
        }
        //**************************** 27 **************************
        x = InfInt("-1239238124841894120044399");
        y = InfInt("-23949349292393492934234");
        x += y;
        if (x == InfInt("-1263187474134287612978633")) {
            counter++;
            cout << "Test 27: Passed" << endl;
        } else {
            cout << "Test 27: failed " << endl;
        }
        //**************************** 28 **************************
        x = InfInt("1924912491249124900019123810384777940113248172464533728193719463811283");
        y = InfInt("0");
        if (x % x == 0) {
            counter++;
            cout << "Test 28: Passed" << endl;
        } else {
            cout << "Test 28: failed " << endl;
        }
        //**************************** 29 **************************
        x = InfInt(1);
        y = InfInt(-1);
        if (x + y == InfInt("0") && y - x == InfInt("-2")) {
            counter++;
            cout << "Test 29: Passed" << endl;
        } else {
            cout << "Test 29: failed " << endl;
        }
        //**************************** 30 **************************
        x = InfInt("12033844747447477419238341100000023881487247123941238");
        y = InfInt("9183812377474471912304048575710230192384664");
        z = InfInt("-12383484848484571230124957123658129394");
        InfInt k("-494912384875111111");
        InfInt m = x + y + z + k;
        if (m == InfInt("12033844756631277413227964527732841837327968783085397")) {
            counter++;
            cout << "Test 30: Passed" << endl;
        } else {
            cout << "Test 30: failed " << endl;
        }
        //**************************** 31 **************************
        m = x - y - z - k;
        if (m == InfInt("12033844738263677425248717672267205925646525464797079")) {
            counter++;
            cout << "Test 31: Passed" << endl;
        } else {
            cout << "Test 31: failed " << endl;
        }
        //**************************** 32 **************************
        m = ((x / y) * z) / k;
        if (m == InfInt("32786567875990168192572669077")) {
            counter++;
            cout << "Test 32: Passed" << endl;
        } else {
            cout << "Test 32: failed " << endl;
        }
        //**************************** 33 **************************
        m = ((x + y) * z) / k;
        if (m == InfInt("301105688131776768002081410182798520404298608825234724685035167389128258")) {
            counter++;
            cout << "Test 33: Passed" << endl;
        } else {
            cout << "Test 33: failed " << endl;
        }
        //**************************** 34 **************************
        x = InfInt("312947412301230293248128378446572349812381231923111111110012398124");
        if ((x & x) == x) {
            counter++;
            cout << "Test 34: Passed" << endl;
        } else {
            cout << "Test 34: failed " << endl;
        }
        //**************************** 35 **************************
        y = InfInt("0");
        if ((x & y) == y) {
            counter++;
            cout << "Test 35: Passed" << endl;
        } else {
            cout << "Test 35: failed " << endl;
        }
        //**************************** 36 **************************
        y = InfInt("-1");
        x = y * x;
        if ((x & x) == x) {
            counter++;
            cout << "Test 36: Passed" << endl;
        } else {
            cout << "Test 36: failed " << endl;
        }
        //**************************** 37 **************************
        /*
         * x=[01010101000010010100111010000110011010101101110000010111001]
         * y=[00000000000000000000000000000000000101111001111100111001111]
         * z=[00000000000000000000000000000000000000101001110000010001001]
         */
        x = InfInt("191484847101239481");
        y = InfInt("12384719");
        z = InfInt("1368201");
        if ((x & y) == z) {
            counter++;
            cout << "Test 37: Passed" << endl;
        } else {
            cout << "Test 37: failed " << endl;
        }
        //**************************** 38 **************************
        /*
         * x=[01010101000010010100111010000110011010101101110000010111001]
         * y=[00000000000000000000000000000000000101111001111100111001111]
         * z=[01010101000010010100111010000110011111111101111100111111111]
         */
        z = InfInt("191484847112255999");
        if ((x | y) == z) {
            counter++;
            cout << "Test 38: Passed" << endl;
        } else {
            cout << "Test 38: failed " << endl;
        }
        //**************************** 39 **************************
        /*
         * x=[01010101000010010100111010000110011010101101110000010111001]
         * y=[00000000000000000000000000000000000101111001111100111001111]
         * z=[01010101000010010100111010000110011111010100001100101110110]
         */
        z = InfInt("191484847110887798");
        if ((x ^ y) == z) {
            counter++;
            cout << "Test 39: Passed" << endl;
        } else {
            cout << "Test 39: failed " << endl;
        }
        //**************************** 40 **************************
        /*
         * x=[1111111]
         * y=[0000000]
         */
        x = InfInt("-1");
        y = InfInt("0");
        if ((x & y) == y) {
            counter++;
            cout << "Test 40: Passed" << endl;
        } else {
            cout << "Test 40: failed " << endl;
        }
        //**************************** 41 **************************
        /*
         * x=[1111111]
         * r=[1100000]
         */
        x = InfInt("-1");
        InfInt r("-32");
        if ((x & r) == r) {
            counter++;
            cout << "Test 41: Passed" << endl;
        } else {
            cout << "Test 41: failed " << endl;
        }
        //**************************** 42 **************************
        /*
         * x=[1111111]
         * r=[1100000]
         */
        if ((x | r) == x) {
            counter++;
            cout << "Test 42: Passed" << endl;
        } else {
            cout << "Test 42: failed " << endl;
        }
        //**************************** 43 **************************
        /*
       * x=[0101011100100011010100011100001001001101011100100101101110110000011110011011001110110011100010001110011011000001101010001100110101111101000011101000111010111011000111000101000000100011011010110110101111100000111000001011001011000111]
       * r=[1100000]
       */
        x = InfInt("2349234923949912391923912394447474746466412941010230000000129348711111");
        y = InfInt("-25");
        if ((x | r) == y) {
            counter++;
            cout << "Test 43: Passed" << endl;
        } else {
            cout << "Test 43: failed " << endl;
        }
        //**************************** 44 **************************
        x = InfInt("1293192319239190000000011124123");
        if ((x >> 0) == x && (x << 0) == x) {
            counter++;
            cout << "Test 44: Passed" << endl;
        } else {
            cout << "Test 44: failed " << endl;
        }
        //**************************** 45 **************************
        x = InfInt("-1293192319239190000000011124123");
        if ((x >> 0) == x && (x << 0) == x) {
            counter++;
            cout << "Test 45: Passed" << endl;
        } else {
            cout << "Test 45: failed " << endl;
        }
        //**************************** 46 **************************
        x = InfInt("12031203102303039494949494941192384597661263");
        if ((x >> 2000) == 0) {
            counter++;
            cout << "Test 46: Passed" << endl;
        } else {
            cout << "Test 46: failed " << endl;
        }
        //**************************** 47 **************************
        /*
         * x   =   [010101001100010101100011]
         * y   =   [011001011011100110101010]
         * y>>=10 =[000000000001100101101110] = 6510
         */
        x = InfInt("5555555");
        y = x + InfInt("1111111");
        y >>= 10;
        if (y == InfInt(6510)) {
            counter++;
            cout << "Test 47: Passed" << endl;
        } else {
            cout << "Test 47: failed " << endl;
        }
        //**************************** 48 **************************
        /*
         * x   =   [101110101100011001101011011101010111111000101110100010010111101111010100100110]
         * y   =   [101110101100011001101011011101010111111000101110100010010111101111010100100110000000000000]
         * y>>=10 =[000000000001100101101110] = 6510
         */
        x = InfInt("-81726363810102000028378");
        y = x << 12;
        if (y == InfInt("-334751186166177792116236288")) {
            counter++;
            cout << "Test 48: Passed" << endl;
        } else {
            cout << "Test 48: failed " << endl;
        }
        //**************************** 49 **************************
        /*
        * x   =   [101110101100011001101011011101010111111000101110100010010111101111010100100110]
        * y   =   [111111111111111111111111111111111111111111111111111111111111111111111111111111] =-1
        */
        x = InfInt("-81726363810102000028378");
        y = x >> 100;
        if (y == InfInt("-1")) {
            counter++;
            cout << "Test 49: Passed" << endl;
        } else {
            cout << "Test 49: failed " << endl;
        }
        //**************************** 50 **************************
        x = InfInt("-81726363810102000028378");
        y = x >> 1;

        if (y == InfInt("-40863181905051000014189")) {
            counter++;
            cout << "Test 50: Passed" << endl;
        } else {
            cout << "Test 50: failed " << endl;
        }

    }catch (char const* e){
        cout<<e<<endl;
        cout<<"That's not supposed to happen !!!!!!!!!!!!"<<endl;

    }
    //_--------------------------------------------------
    cout<<endl<<endl;
    cout<<"passed:["<<counter<<"/"<<50<<"]"<<endl<<endl;





    return 0;


}
