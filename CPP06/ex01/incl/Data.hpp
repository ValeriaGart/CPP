#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>

class Data {

    private:
	    const std::string _name;
    public:
        Data( void );
        Data(const Data& to_copy);
        Data& operator=(const Data& to_assign);
        ~Data();

	    std::string ft_get_name() const;
} ;

#endif