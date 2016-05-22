#ifndef CVOR_H
#define CVOR_H


template <typename Type>
class Cvor
{
	private:
		Type info;
		Cvor* link;
	public:
	    Cvor() = default;
	    Cvor(const Type& i, Cvor * l = nullptr) : info(i), link(l) {};
		Type& getInfo() {return info;}
		Cvor* getLink() {return link;}
		void setInfo(Type T) {info=T;}
		void setLink(Cvor* L) {link=L;}
};

#endif
