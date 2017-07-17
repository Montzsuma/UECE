#include <iostream>
#include <cmath>
using namespace std;

int MetodoCongruenteLinear(int seed, int multiplier, int module, int addition)
{
    /*
        Se addition = 0, o método é chamado Método Congruente Linear Multiplicativo.
        Após a primeira chamada, seed deverá sempre ser o último valor retornado.
    */
    return ((multiplier*seed + addition) % module);
}

int MetodoDeSchrage(int seed, int multiplier, int module)
{
    int q = module/multiplier;
    int r = module%multiplier;
    int gx = (multiplier*seed)%q - r*(seed/q);
    int hx = (seed/q) - (multiplier*seed/module);
    
    return (gx + module*hx);
}

double Distribuicao_Geometrica_Inversa(double seed, double probability)
{
    double constant = 1/(log(1-probability));
    return ceil(constant*log(1-seed));
}

int  main()
{
    int seed = 27;
    for(int i = 0; i < 100; i++)
    {
        //seed = MetodoCongruenteLinear(seed, 17, 100, 43);
        seed = MetodoDeSchrage(seed, 17, 100);
        cout << "Random " << i << ": " << seed << endl;
    }
}
