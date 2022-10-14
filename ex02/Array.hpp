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
		Array<T>(unsigned int n):
			_array(new T[n]),
			_n(n) {}
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

		unsigned int	size() const { return (_n); }
		T				getElement(unsigned int i) const {
			if (i >= _n) throw (Array::OutOfBound());
			return (_array[i]);
		}
		void			setElement(unsigned int i, T element) {
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
