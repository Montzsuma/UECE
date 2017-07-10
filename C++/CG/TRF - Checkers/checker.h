class Checker
{
    //Variáveis:
    public:
        int id, cor, id_pos;
        float x, y;
        bool dama, viva, select;
    //Funções:
        void set_id(int x)
        {
            id = x;
        }

        void set_id_pos(int x)
        {
            id_pos = x;
        }

        void set_color(int x)
        {
            cor = x;
        }
        
        void set_xy(float a, float b)
        {
            x = a;
            y = b;
        }
        
        void set_king(bool a)
        {
            dama = a;
        }

        void set_param(bool a, bool b)
        {
            dama = a;
            viva = b;
        }
        
        void set_selected(bool a)
        {
            select = a;
        }
        
        void invert_xy()
        {
            x*=-1;  y*=-1;
        }
};
