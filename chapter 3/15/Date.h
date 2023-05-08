class Date{
    public:
        Date(int,int,int);
        int getDay() const;
        void setDay(int );  
        int getMonth() const;
        void setMonth(int ); 
        int getYear() const;
        void setYear(int );    
        void displayDate() const;
    private:
        int day;
        int month;
        int year;
};