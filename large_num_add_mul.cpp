// These functions can add and multiply numbers that are too large to calculate as integers.
// Note that these functions deal with numbers 'reversed'.
// ll型でも扱えない巨大な整数同士の加算、積算をします
// ll型でも扱えない巨大な整数同士の加算、積算をしたい場合にどうぞ

string int_to_string(int x) {
    string res;

    while (x > 0) {
        res.push_back(x % 10 + '0');
        x /= 10;
    }

    return res;
}

string stplus(string* a, string* b) {
    int i, la, lb, kr, s;
    string res;

    if (a->size() < b->size()) {
        swap(a, b);
    }

    kr = 0;
    for (i = 0; i < a->size(); i++) {
        la = (*a)[i] - '0';
        if (i >= b->size()) {
            lb = 0;
        }
        else {
            lb = (*b)[i] - '0';
        }
        s = la + lb + kr;
        if (s >= 10) {
            res.push_back(s - 10 + '0');
            kr = 1;
        }
        else {
            res.push_back(s + '0');
            kr = 0;
        }
    }

    if (kr == 1) {
        res.push_back('1');
    }

    return res;
}

string stmultiple(string* a, string* b) {
    int i, j, kb;
    string res;

    res = "0";

    for (i = 0; i < b->size(); i++) {
        if ((*b)[i] == '0') continue;

        vector<int> rin;
        string resp;

        kb = (*b)[i] - '0';
        for (j = 0; j < a->size(); j++) {
            rin.push_back(((*a)[j] - '0') * kb);
        }

        for (j = 0; j < rin.size(); j++) {
            if (j == rin.size() - 1) {
                if (rin[j] < 10) break;
                rin.push_back(rin[j] / 10);
            }
            else {
                rin[j + 1] += rin[j] / 10;
            }
            rin[j] %= 10;
        }

        for (j = 0; j < i; j++) {
            resp.push_back('0');
        }

        for (j = 0; j < rin.size(); j++) {
            resp.push_back(rin[j] + '0');
        }

        res = stplus(&res, &resp);
    }

    return res;
}