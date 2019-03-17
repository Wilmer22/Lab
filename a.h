using namespace std;

class Elo{
    public:
        Elo();
        Elo(double,double,double);

        double get_key();
        double get_ra();
        double get_rb();
        double get_ea();
        double get_eb();

        void set_key(double);
        void set_ra(double);
        void set_rb(double);
        void set_ea(double);
        void set_eb(double);


    private:
        double _key;
        double _ra;    
        double _rb;
        double _ea;
        double _eb;
};
