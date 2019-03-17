#include <iostream>
#include <fstream> 
#include <math.h>  
#include "a.h"   
using namespace std;
void elo_system(ifstream& input_file,ofstream& output_file);
int main()
{
    ifstream fin;      //宣告fstream物件
    ofstream fout;
    
    fin.open("file.in");
    if(fin.fail())
    {
        cout<<"Input file open failed";
        exit(1);
    }

    fout.open("file.out",ios::trunc);
    if(fout.fail())
    {
        cout<<"Output file open failed";
        exit(1);
    }
    elo_system(fin,fout);
    

    fin.close();
    fout.close();
    cout<<"The end \n";

    return 0;
}

void elo_system(ifstream& input_file,ofstream& output_file){
    
    double input_num[9];
    double next;
    int index = 0;
    while(input_file >> next){
        input_num[index]=next;
        index++;
    }
    
    Elo athlete(input_num[0],input_num[1],input_num[2]);
    double output_ra;
    double output_rb;
    double ea_eb;
    double key = athlete.get_key();
    index = 0;
    output_file << athlete.get_ra() << "  " << athlete.get_rb() <<"\n";
    for(int i = 0; i < 6; i++)
    {
        if(input_num[3+index]==1.0){

            output_ra = athlete.get_ra()+key*(1-athlete.get_ea());
            output_rb = athlete.get_rb()+key*(0-athlete.get_eb());
        }else if (input_num[3+index]==0.5){

            output_ra = athlete.get_ra()+key*(0.5-athlete.get_ea());
            output_rb = athlete.get_rb()+key*(0.5-athlete.get_eb());
        }else if (input_num[3+index]==0){
           
            output_ra = athlete.get_ra()+key*(0-athlete.get_ea());
            output_rb = athlete.get_rb()+key*(1-athlete.get_eb());
        };
        
        output_ra = nearbyint(output_ra);
        output_rb = nearbyint(output_rb);

        athlete.set_ra(output_ra);
        athlete.set_rb(output_rb);
        
        ea_eb = (output_rb-output_ra)/400;
        athlete.set_ea(1/(1+pow(10,ea_eb)));

        ea_eb = (output_ra-output_rb)/400;
        athlete.set_eb(1/(1+pow(10,ea_eb)));
        
        index++;
        output_file << output_ra << "  " << output_rb <<"\n";
    }

    
    return;
}

Elo::Elo(){
    _key = 32.0;
    _ra = 1613;
    _rb = 1609;
    _ea = 0.506;
    _eb = 0.494;
}

Elo::Elo(double key, double ra , double rb){
    _key = key;
    _ra = ra;
    _rb = rb;
    _ea = 0.506;
    _eb = 0.494;
}

void Elo::set_key(double key){
    _key = key;
}

void Elo::set_ra(double ra){
    _ra = ra;
}

void Elo::set_rb(double rb){
    _rb = rb;
}

void Elo::set_ea(double ea){
    _ea = ea;
}

void Elo::set_eb(double eb){
    _eb = eb;
}

double Elo::get_key(){
    return _key;
}

double Elo::get_ra(){
    return _ra;
}

double Elo::get_rb(){
    return _rb;
}

double Elo::get_ea(){
    return _ea;
}

double Elo::get_eb(){
    return _eb;
}