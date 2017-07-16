class Board
{
    //Variáveis:
    public:
        int x, y;
        int id, id_checker, id_u_left, id_u_right, id_d_left, id_d_right;
        bool select, busy;
    //Funções:
        void set_id(int x)
        {
            id = x;
        }

        void set_id_checker(int x)
        {
            id_checker = x;
        }

        void set_reset_ids_up_down()
        {
            id_u_left = -1;
            id_d_left = -1;
            id_u_right = -1;
            id_d_right = -1;
        }

        void set_id_u_lr(int x, int y)
        {
            if(x>0)
                id_u_left = x;
            if(y>0)
                id_u_right = y;
        }
        
        void set_id_d_lr(int x, int y)
        {   
            if(x>=0)
                id_d_left = x;
            if(y>=0)
                id_d_right = y;
        }

        void set_xy(int a, int b)
        {
            x = a;
            y = b;
        }

        void set_busy(bool c)
        {
            busy = c;
        }

        void set_selected(bool a)
        {
            select = a;
        }

        void invert_xy()
        {
            x*=-1;
            y*=-1;
        }

        void invert_path()
        {
            swap(id_u_left, id_d_right);
            swap(id_u_right, id_d_left);
        }
};
