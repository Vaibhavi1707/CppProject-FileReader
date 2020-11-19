class File
{
    public:
        virtual bool read() = 0;
        virtual bool modify() = 0;
        virtual bool write() = 0;
};
