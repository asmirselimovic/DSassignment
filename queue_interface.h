#ifndef H_INTERFACE_QUEUE
#define H_INTERFACE_QUEUE

template <typename Type>
class queue_interface
{
    public:
        virtual void push(const Type & val) = 0;   
        virtual void push(Type&& val) = 0;  
        virtual Type& front() = 0;
        virtual const Type& front() const = 0;
        virtual Type& back() = 0;
        virtual const Type& back() const = 0;
        virtual void pop() = 0;     
        virtual size_t size() const = 0;
        virtual bool empty() const = 0;        
};

#endif
