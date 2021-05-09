class BIT {
  private:
    int bit[100010] = {};

  public:
    int sum(int i) {
        int s = 0;
        while (i > 0) {
            s += bit[i];
            i -= i & (-i);
        }
        return s;
    }

    void add(int n, int i, int k) {
        while (i <= n) {
            bit[i] += k;
            i += i & (-i);
        }
    }

};