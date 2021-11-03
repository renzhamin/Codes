struct Player{    
    char name[50],position[50];
    int age,rating,salary;
    struct Player *next;
};


struct Clubs{
    char name[50];
    int year,income;
    struct Clubs *next;
    struct Player *player;
}*root;