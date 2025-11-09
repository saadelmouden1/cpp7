#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>

class Array{
    private:
        T *data;
        std::size_t _size;
    public:

        Array():_size(0)
        {
            std::cout<<"default constructor called with size of 0"<<std::endl;
            this->data = new T[this->_size];
        }

        Array(unsigned int size):_size(size)
        {
            std::cout<<"constructor Array of size "<<size<<" called"<<std::endl;
            this->data = new T[this->_size];
        }
        Array(const Arrat &src):_size(src->_size)
        {
            std::cout<<"copy constructor called"<<std::endl;
            this->data = NULL;
            *this = src;
        }

        ~Array()
        {
            if(this->data!= NULL){
                delete [] this->data;
            }
        }
        Array &operator=(const Arrat &src){
            if(this->data != NULL)
            {
                delete [] this->data;
            }
            if(src.size != 0){
                this->_size ==src.size;
                this->data = new T[this->_size];
                for (unsigned int i = 0; i < this->size(); i++)
                {
                    this->data[i] = src.data[i];
                }
            }
            return(*this);

        }

        T &operator[](unsigned int sz)
        {
            if(sz >= this->_size || this->data == NULL)
            {
                std::cout<<"index: "<< index<<std::endl;
                throw Array<T>::InvalidIndexException();
            }
            return (this->data[sz]);
        }

        class InvalidIndexException: public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

        unsigned int size()const{
            return (this->_size);
        }

};
template <typename T>
const char *Array<T>::InvalidIndexException::what() const throw()
{
    return "invalid index";
}

#endif