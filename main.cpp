#include "Driver.h"

int main()
{
    cout<<"\n######## INSTRUCTION : DON'T GIVE SPACE BETWEEN THE INPUT TYPE STRING ########\n"<<endl;
    driver menu_driver;
    menu_driver.start();
    return 0;
}






/*#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Video
{
    private:
        string title;
        string creator;
        int price;
        string ref_no;
    public:
        Video(){}
        Video(string title, string creator, int price, string ref_no)
        {
            this -> title = title;
            this -> creator = creator;
            this -> price = price;
            this -> ref_no = ref_no;
        }
        void set_title(string title){this -> title = title;}
        void set_creator(string creator){this -> creator = creator;}
        void set_ref_no(string ref_no){this -> ref_no = ref_no;}
        void set_price(int price){this -> price = price;}


        string get_title(){return this -> title;}
        string get_creator(){return this -> creator;}
        int get_price(){return this -> price;}
        string get_ref_no(){return this -> ref_no;}



};
class Registered_user;
class Video_library
{
    private:
        map<string, Video> videos;
        unordered_map<int, string> verification;
        map<int, Registered_user> user_detail;
    public:
        Video_library();

        pair<bool, Registered_user> login(int id, string password);
        void register_to_library(int id, string password);

        void add_video_into_library(Video & vid);
        void remove_video_from_library(string ref_no);

        void see_all_collection();
        void see_all_user();
        void add_new_user(Registered_user & user);
        void remove_user(Registered_user & user);

        friend ofstream & operator<<(ofstream & ofs,Video & vid);
        friend ifstream & operator>>(ifstream & ifs,Video & vid);
        friend ostream & operator<<(ostream & os,Video & vid);

        friend ofstream & operator<<(ofstream & ofs, Registered_user & user);
        friend ifstream & operator>>(ifstream & ifs, Registered_user & user);
        friend ostream & operator<<(ostream & os, Registered_user & user);

        ~Video_library();

};

class User
{
    private:
        string f_name;
        string l_name;
        int id;
        string password;
    public:
        User(){}
        void set_f_name(string f_name){this -> f_name = f_name;}
        void set_l_name(string l_name){this -> l_name = l_name;}
        void set_user_id(int id){this -> id = id;}
        void set_password(string password){this -> password = password;}

        string get_f_name(){return this -> f_name;}
        string get_l_name(){return this -> l_name;}
        string get_password(){return this -> password;}
        int get_user_id(){return this->id;}

        void see_all_video_collection(Video_library & library);


};

class Registered_user:public User
{
    private:
        int no_of_video_rented;
        int no_of_video_returned;
        string current_video_ref_no;
    public:
        Registered_user(){}
        void set_no_of_video_rented(int rented){this -> no_of_video_rented = rented;}
        void set_no_of_video_returned(int returned){this -> no_of_video_returned = returned;}
        void set_current_video_ref_no(string ref_no){this -> current_video_ref_no = ref_no;}

        int get_no_of_video_rented(){return this -> no_of_video_rented;}
        int get_no_of_video_returned(){return this -> no_of_video_returned;}
        string get_current_video_ref_no(){return this -> current_video_ref_no;}

        pair<bool, Registered_user> verify(Video_library & library);
        void rent_video(Video_library & library);
        void return_video(Video_library & library);

        void user_account_detail(Registered_user & user);
};

class Guest_user: public User
{
    public:
        Guest_user(){}
        void sign_up(Video_library & library);

};

class Librarian
{
    private:
        string f_name;
        string l_name;
        string password;
        int id;
    public:
        Librarian(string f_name, string l_name, string password, int id)
        {
            this -> f_name = f_name;
            this -> l_name = l_name;
            this -> password = password;
            this -> id = id;
        }
        bool verify();
        int get_id(){return this->id;}
        string get_password(){return this->password;}
        void add_video_to_library(Video_library & library);
        void remove_video_from_library(Video_library & library);
        void see_all_user_detail(Video_library & library);
        void description_librarian();

};




/////////////// Video Library //////////////////////////

ofstream & operator<<(ofstream & ofs,Video & vid)
{
    ofs<<vid.get_title()<<endl;
    ofs<<vid.get_creator()<<endl;
    ofs<<vid.get_ref_no()<<endl;
    ofs<<vid.get_price()<<endl;
    return ofs;
}


ifstream & operator>>(ifstream & ifs,Video & vid)
{

    string title;
    string creator;
    int price;
    string ref_no;

    ifs>>title;
    ifs>>creator;
    ifs>>ref_no;
    ifs>>price;

    vid.set_title(title);
    vid.set_creator(creator);
    vid.set_ref_no(ref_no);
    vid.set_price(price);

   return ifs;
}


ostream & operator<<(ostream & os,Video & vid)
{

   os<<"Title      : "<<vid.get_title()<<endl;
   os<<"Creator    : "<<vid.get_creator()<<endl;
   os<<"Ref no     : "<<vid.get_ref_no()<<endl;
   os<<"Price      : "<<vid.get_price()<<endl;
   return os;
}



ofstream & operator<<(ofstream & ofs, Registered_user & user)
{
    ofs<<user.get_f_name()<<endl;
    ofs<<user.get_l_name()<<endl;
    ofs<<user.get_user_id()<<endl;
    ofs<<user.get_password()<<endl;
    ofs<<user.get_no_of_video_rented()<<endl;
    ofs<<user.get_no_of_video_returned()<<endl;
    ofs<<user.get_current_video_ref_no()<<endl;

    return ofs;
}



ifstream & operator>>(ifstream & ifs, Registered_user & user)
{
    string f_name;
    string l_name;
    string password;
    int id;
    int no_of_video_rented;
    int no_of_video_returned;
    string current_video_ref_no;

    ifs>>f_name;
    ifs>>l_name;
    ifs>>id;
    ifs>>password;
    ifs>>no_of_video_rented;
    ifs>>no_of_video_returned;
    ifs>>current_video_ref_no;

    user.set_f_name(f_name);
    user.set_l_name(l_name);
    user.set_user_id(id);
    user.set_password(password);
    user.set_no_of_video_rented(no_of_video_rented);
    user.set_no_of_video_returned(no_of_video_returned);
    user.set_current_video_ref_no(current_video_ref_no);

    return ifs;
}


ostream & operator<<(ostream & os, Registered_user & user)
{
    os<<"First name                  :  "<<user.get_f_name()<<endl;
    os<<"Last name                   :  "<<user.get_l_name()<<endl;
    os<<"User Id                     :  "<<user.get_user_id()<<endl;
    os<<"user password               :  "<<user.get_password()<<endl;
    os<<"no of video rented yet      :  "<<user.get_no_of_video_rented()<<endl;
    os<<"no of video returned        :  "<<user.get_no_of_video_returned()<<endl;
    os<<"current video reference no  :  "<<user.get_current_video_ref_no()<<endl;

    return os;
}




Video_library::Video_library()
{
   Video add_video;
   ifstream infile;
   infile.open("library.txt");
   if(!infile)
   {
    return;
   }
   while(infile)
   {
      infile>>add_video;
      videos.insert({add_video.get_ref_no(), add_video});
   }
   infile.close();

   Registered_user user;
   ifstream infile_2;
   infile_2.open("register_user.txt");
   if(!infile_2)
    return;
   while(infile_2)
   {
       infile_2>>user;
       user_detail.insert({user.get_user_id(), user});
       verification.insert({user.get_user_id(), user.get_password()});
   }
   infile_2.close();
}



void Video_library::add_video_into_library(Video & vid)
{

     videos[vid.get_ref_no()] = vid;

}



void Video_library::remove_video_from_library(string ref_no)
{

    auto it = videos.find(ref_no);
    if(it != videos.end())
    {
        videos.erase(it);
        cout<<"\n****video has been erased******\n"<<endl;
    }
    else
    {
       cout<<"\n*****you have given the incorrect ref no******\n"<<endl;
    }
}

void Video_library::see_all_collection()
{
    if(videos.empty())
        cout<<"\n***********No videos are available in library*********\n"<<endl;
    else
    {
        cout<<"\n**********collections of videos in library*************\n"<<endl;
        auto it = videos.begin();
        while(++it != videos.end())
        {
            cout<<it -> second<<endl;
        }
        cout<<endl;

    }
}

 void Video_library::see_all_user()
 {
     if(user_detail.empty())
        cout<<"\n***********Library has no user until now.*********\n"<<endl;
    else
    {
        cout<<"\n**********Detail of all users*************\n"<<endl;
        auto it = user_detail.begin();
        while(++it != user_detail.end())
        {
            cout<<it -> second<<endl;
        }
        cout<<endl;

    }
 }


pair<bool, Registered_user> Video_library::login(int id, string password)
{
    Registered_user user;
    auto it = verification.find(id);
    if(it != verification.end())
    {
        if(it -> second == password)
         {
              auto it1 = user_detail.find(id);
              return {true, it1->second};
         }
        else
        {
            cout<<"\n*****you have given wrong password******\n"<<endl;
            return {false, user};
        }
     }
    else
    {
        cout<<"\n*****you have given wrong id******\n"<<endl;
        return {false, user};
    }
    return {false, user};
}


void Video_library::register_to_library(int id, string password)
{
    verification[id] = password;
}


void Video_library::add_new_user(Registered_user & user)
{
    user_detail[user.get_user_id()] = user;
}
void Video_library::remove_user(Registered_user & user)
{
    user_detail.erase(user.get_user_id());
    verification.erase(user.get_user_id());
}



Video_library::~Video_library()
{
  if(!videos.empty())
  {
       ofstream outfile("library.txt");
       auto it = videos.begin();
       while(++it != videos.end())
       {
           outfile<<it->second;
       }
       outfile.close();
  }

  if(!user_detail.empty())
  {

      ofstream outfile_2("register_user.txt");
       auto it = user_detail.begin();
       while(++it != user_detail.end())
       {
           outfile_2<<it->second;
       }
       outfile_2.close();
  }


}


//////////////// Librarian ////////////////////////

bool Librarian::verify()
{
            int id;
            string password;
            cout<<"Enter the id : ";
            cin>>id;
            cout<<"Enter the password :  ";
            cin>>password;
            if(this -> id == id)
            {
                 if(this -> password == password)
                    return true;
                else
                {
                    cout<<"\n*****you have given wrong password******\n"<<endl;
                    return false;
                }
            }
            else
            {
                    cout<<"\n*****you have given wrong id******\n"<<endl;
                    return false;
            }
            return false;

}
void Librarian::add_video_to_library(Video_library & library)
{
    string title;
     string creator;
     int price;
     string ref_no;
     cout<<"Enter the title : ";
     cin>>title;
     cout<<"Enter the creator : ";
     cin>>creator;
     cout<<"Enter the price : ";
     cin>>price;
     cout<<"Enter the ref no : ";
     cin>>ref_no;
     Video new_video(title, creator, price, ref_no);
     library.add_video_into_library(new_video);
}
void Librarian::remove_video_from_library(Video_library & library)
{
    string ref_no;
    cout<<"Enter the reference no  : ";
    cin>>ref_no;
    library.remove_video_from_library(ref_no);
}


void Librarian::see_all_user_detail(Video_library & library)
{
    library.see_all_user();
}

///////////////User////////////////////////////////

void User::see_all_video_collection(Video_library & library)
{
    library.see_all_collection();
}

//////////////Registered user///////////////////////

pair<bool, Registered_user> Registered_user::verify(Video_library & library)
{
    int id;
    string  password;
    cout<<"Enter the User id : ";
    cin>>id;
    cout<<"Enter the Password : ";
    cin>>password;
    pair<bool, Registered_user> register_user = library.login(id, password);
    return {register_user.first, register_user.second};

}
void Registered_user::rent_video(Video_library & library)
{
    string ref_no;
    cout<<"Enter the ref no : ";
    cin>>ref_no;
    set_current_video_ref_no(ref_no);
    int rented_video = get_no_of_video_rented();
    set_no_of_video_rented(rented_video + 1);

}
void Registered_user::return_video(Video_library & library)
{
    set_current_video_ref_no("NULL");
    int returned_video = get_no_of_video_returned();
    set_no_of_video_returned(returned_video + 1);

    cout<<"\n***********You have successfully returned the video********\n"<<endl;
}

void Registered_user::user_account_detail(Registered_user & user)
{
    cout<<user<<endl;
}

///////////////////Guest user///////////////////////

void Guest_user::sign_up(Video_library & library)
{
    string f_name;
    string l_name;
    int id;
    string password;

    cout<<"Enter the first name :  ";
    cin>>f_name;
    cout<<"Enter the last name  :  ";
    cin>>l_name;
    cout<<"Enter the id : ";
    cin>>id;
    cout<<"Enter the password :  ";
    cin>>password;


    Registered_user new_user;
    new_user.set_f_name(f_name);
    new_user.set_l_name(l_name);
    new_user.set_user_id(id);
    new_user.set_password(password);
    new_user.set_current_video_ref_no("NULL");
    new_user.set_no_of_video_rented(0);
    new_user.set_no_of_video_returned(0);
    library.register_to_library(id, password);
    library.add_new_user(new_user);
}
*/
/*
int main()
{

    Video_library new_video_libarary;
    Librarian librarian("James", "Bond", "password", 180101005);
    int option;
    option = 0;
    while(option < 4)
    {
        cout<<"\n*****User Type******\n"<<endl;
        cout<<"1.for Librarian "<<endl;
        cout<<"2.for Register User"<<endl;
        cout<<"3.for Guest User"<<endl;
        cout<<"4.for coming out from project"<<endl;
        cout<<"Enter option : ";
        cin>>option;
        if(option == 1)
        {
            bool is_librarian = librarian.verify();
            if(is_librarian)
            {
                int option_1 = 0;
                while(option_1 < 5)
                {
                cout<<"\n******Menu Driver******\n"<<endl;
                cout<<"1.For add video in Library"<<endl;
                cout<<"2.For remove video from library"<<endl;
                cout<<"3.For seeing collection of video from library"<<endl;
                cout<<"4.For seeing all user Detail"<<endl;
                cout<<"5.Main menu\n"<<endl;
                cout<<"Enter your option : ";
                cin>>option_1;
                if(option_1 == 1 )
                     librarian.add_video_to_library(new_video_libarary);
                else if(option_1 == 2)
                     librarian.remove_video_from_library(new_video_libarary);
                else if(option_1 == 3)
                     new_video_libarary.see_all_collection();
                else if(option_1 == 4)
                      librarian.see_all_user_detail(new_video_libarary);
                 }
            }

        }
        else if(option == 2)
        {
             int option_2;
             Registered_user user;
             pair<bool, Registered_user> is_registered_user = user.verify(new_video_libarary);
             if(is_registered_user.first == true)
             {
                option_2 = 0;
                while(option_2 < 6)
                {
                     cout<<"\n*******MENU DRIVER******\n"<<endl;
                     cout<<"1.For rent new video"<<endl;
                     cout<<"2.For returning video"<<endl;
                     cout<<"3.To look on library collection"<<endl;
                     cout<<"4.To Cancel membership"<<endl;
                     cout<<"5.To see User account detail"<<endl;
                     cout<<"6.Main menu"<<endl;
                     cout<<"Enter your own choice : "<<endl;
                     cin>>option_2;
                     if(option_2 == 1)
                         is_registered_user.second.rent_video(new_video_libarary);

                     else if(option_2 == 2)
                         is_registered_user.second.return_video(new_video_libarary);

                     else if(option_2 == 3)
                         is_registered_user.second.see_all_video_collection(new_video_libarary);

                     else if(option_2 == 4)
                         new_video_libarary.remove_user(is_registered_user.second);
                     else if(option_2 == 5)
                         is_registered_user.second.user_account_detail(is_registered_user.second);

                }
             }

        }
        else if(option == 3)
        {
               int option_3;
               Guest_user user;
               option_3 = 0;
               while(option_3 < 3)
               {
                   cout<<"\n*********MENU DRIVER********\n"<<endl;
                   cout<<"1.For register"<<endl;
                   cout<<"2.For see video collection"<<endl;
                   cout<<"3.Main menu"<<endl;
                   cout<<"Enter your option: ";
                   cin>>option_3;
                   if(option_3 == 1)
                   {
                       user.sign_up(new_video_libarary);
                       cout<<"\n*************You have registered successfully*********\n"<<endl;
                   }
                   if(option_3 == 2)
                   {
                       user.see_all_video_collection(new_video_libarary);
                   }
               }
        }
    }
    cout<<"\n*******Thank you very much for visiting our project*****\n"<<endl;
    return 0;
}*/



