#ifndef __F_GENERAL_H__
#define __F_GENERAL_H__

#define READ_ONLY_PROPERTY(type, name) \
    protected: \
        type _##name; \
    public: \
        type name() const \
        { \
            return _##name; \
        }; \
    private:

#define PROPERTY(type, name, setterName) \
        READ_ONLY_PROPERTY(type, name) \
    public: \
        void setterName(type name) \
        { \
            _##name = name; \
        }; \
    private:

#endif
