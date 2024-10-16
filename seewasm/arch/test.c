int call_func(int idx, int x, int y) {
    return function_table[idx](x, y);
}
int main(int a, int b, int c, int d) {
    int result, temp;
    temp = (a + b) << 2;
    result = temp * c;
    if (result < 100) {
        result += 50;
    }
       switch (d % 3) {
        case 0:  // case 0: result = result ^ c
            result ^= c;
            break;
        case 1:  // case 1: result = result + c
            result += c;
            break;
        case 2:  // case 2: result = result - c
            result -= c;
            break;
    }
    result = call_func(d % 2, result, d);
    return result;
}
