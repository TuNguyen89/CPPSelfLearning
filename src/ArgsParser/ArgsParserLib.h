/**
* @ingroup Argument Parse Module
* Argument Parse Module
*/

/*! Argument Parse Module
   

   Example Usage:
    @code
   
    @endcode
*/

#ifndef ARGSPARSER_H_
#define ARGSPARSER_H_

#include "string"
#include "map"
#include "list"

namespace UTILITY
{
    using std::string;
    using std::map;

    class Args
    {
    public:
        Args();
        ~Args();

    private:

        map<char, ArgumentMarshaler> argPaser;

        void parseSchema();
        void parseElement();
    };

    template <class T>
    class ArgumentMarshaler
    {
    public:
        virtual void set(string args);
        virtual T get();
    };

    class BoolArgumentMarshaler : public ArgumentMarshaler<bool>
    {
    public:
        BoolArgumentMarshaler();
        ~BoolArgumentMarshaler();
        void set(string args);
        bool get();

    private:
        bool boolValue;
    };

    class StringArgumentMarshaler : public ArgumentMarshaler < string >
    {
    public:
        StringArgumentMarshaler();
        ~StringArgumentMarshaler();

        void set(string args);
        string get();

    private:
        string stringValue;
    };

    class IntegerArgumentMarshaler : public ArgumentMarshaler < int >
    {
    public:
        IntegerArgumentMarshaler();
        ~IntegerArgumentMarshaler();

        void set(string args);
        int get();

    private:
        int integerValue;
    };

}

#endif