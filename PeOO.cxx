#include <iostream>
#include <string>
#include <vector>
#include <map>

enum Grupo {
    Trabalho, Familia, Amigos
};

enum Parentesco {
    Grandfather, Grandmother, Dad, Mom, Brother, Sister, MaleCousin, FemaleCousin, Other
};

class Contato {
private:
    std::string nome;
    std::vector<std::string> numeros; // Números de telefone
    std::vector<std::string> endereco; // Rua, número, complemento, bairro, cep, cidade, estado
    std::vector<std::string> emails; // Lista de emails
    Data date; // Data de aniversário
    Grupo grupo; // Trabalho, família ou amigos
public:
    std::string get_nome() {
        return nome;
    }
    Grupo get_group() {
        return grupo;
    }
    virtual void print_contato() = 0;
};

class Trabalho : public Contato {
private:
    std::string setor;
    std::string empresa;
    std::map<Data, std::string> reunioes;
public:
    void print_contato() {
        std::cout << get_nome() << std::endl;
    }
};

class Familia : public Contato {
private:
    Parentesco p;
public:
};

class Amigos : public Contato {
private:
    std::map<Data, std::string> reunioes;
public:
};

class Data {
private:
    int Dia;
    int Mes;
    int Ano;
public:
    int get_dia() { return Dia; }
    int get_mes() { return Mes; }
    int get_ano() { return Ano; }
    void print_date() { std::cout << get_dia() << "/" << get_mes() << "/" << get_ano() << std::endl; }
};

class Agenda {
private:
    std::vector<Contato> lista;
public:
    void listar(Grupo group) {
        for(std::vector<Contato>::iterator it = lista.begin(); it != lista.end(); it++)
            if (it->get_group() == group)
                it->print_contato();
    }
};
