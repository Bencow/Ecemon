void menu0();
void menu1();

void menu0()
{
    int choix = 0;

    while(choix != 3)
    {
        cout << "menu0" << endl
             << 1 << endl
             << 2 << " menu1" << endl
             << 3 << " quitter" << endl;
        cin >> choix;

        if(choix == 1)
        {
            cout << "ok" <<endl;
            getchar();
        }
        if(choix == 2)
        {
            menu1();
        }
    }
    cout << "au revoir" << endl;
}




void menu1()
{
    int choix = 0;

    while(choix != 3)
    {
        cout << "menu1" << endl
             << 1 << endl
             << 2 << endl
             << 3 <<" revenir au menu" << endl;
        cin >> choix;

        if(choix == 1)
        {
            cout << "ok" <<endl;
            getchar();
        }
        if(choix == 2)
        {
            cout << "dalkj"<<endl;
            getchar();
        }
    }
}
