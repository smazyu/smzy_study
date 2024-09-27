namespace simulation {
    class string {
    public:
        string(): _str(nullptr) {
        }

        string(char *str): _str(str) {
            ;
        };

        private
        :
            char *_str;
    };

    void test_string1() {
        string s1("hello");
        string s2;
    }
}