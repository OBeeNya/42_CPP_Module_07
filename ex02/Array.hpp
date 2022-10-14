#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <typename T>
class	Array
{

	private:

		T				*_array;
		unsigned int	_n;

	public:

		Array<T>():
			_array(new T*),
			_n(0) {}
		Array<T>(const unsigned int n):
			_array(new T[n]),
			_n(n) { for (int i = 0; i < _n; i++) _array[i] = 0; } 
		Array<T>(const Array &src):
			_n(src.getN()),
			_array(new T[src.size()]) {
				for (int i = 0; i < _n; i++) _array[i] = src.getElement(i);
			}
		~Array<T>() { delete [] _array; }

		Array<T>	&operator=(const Array<T> &rhs) {
			if (this == &rhs) return (*this);
			delete [] _array;
			_n = rhs.size();
			_array = new T[_n];
			for (int i = 0; i < _n; i++) _array[i] = rhs.getElement(i);
			return (*this);
		}
		T			&operator[](const unsigned int i) {
			if (i >= _n) throw (Array::OutOfBound());
			return (_array[i]);
		}

		unsigned int	size() const { return (_n); }
		T				getElement(const unsigned int i) const {
			if (i >= _n) throw (Array::OutOfBound());
			return (_array[i]);
		}
		void			setElement(const unsigned int i, const T element) {
			if (i >= _n) throw (Array::OutOfBound());
			_array[i] = element;
		}

		class	OutOfBound:
			public std::exception {
				public:
					virtual const char*	what(void) const throw(){
						return ("Index out of bounds.");
					}
			};

};

#endif
