#include <iostream>
#include <string>

// Abstract class
class Figura {
  public:
    // Virtual function
    virtual double obwód() const = 0;

    virtual ~Figura() {};
};

class Trójkąt : public Figura {
  public:
    Trójkąt(double x_in, double y_in, double z_in) {
      x = x_in;
      y = y_in;
      z = z_in;
    };

    double obwód() const override {
      return x+y+z;
    };

    // Operator overloading
    Trójkąt operator+(const Trójkąt& other) const {
      double x = this->x + other.x;
      double y = this->y + other.y;
      double z = this->z + other.z;
      return Trójkąt(x, y, z);
    };

    ~Trójkąt() override {};

  private:
    double x;
    double y;
    double z;
};

class Kwadrat: public Figura {
  public:
    Kwadrat(double b) : bok(b) {};
  
    double obwód() const override {
      return 4 * bok;
    };

    // Operator overloading
    Kwadrat operator+(const Kwadrat& other) const {
      double nowy_bok = this->bok + other.bok;
      return Kwadrat(nowy_bok);
    };

    ~Kwadrat() override {};
    
  private:
    double bok;    
};

// Generic type
template <typename T, typename U>
std::string większy_obwód(T x, U y) {
  if (x.obwód() > y.obwód()) {
    return "Pierwszy jest większy";
  }
  else {
    return "Drugi jest większy";
  };
};

int main() {
  Trójkąt t1(3, 4.5, 5);
  Trójkąt t2(6, 8.5, 10);
  Trójkąt t3 = t1 + t2;
  std::cout << "Obwód t1: " << t1.obwód() << "\n";
  std::cout << "Obwód t2: " << t2.obwód() << "\n";
  std::cout << "Obwód t3: " << t3.obwód() << "\n";

  Kwadrat k1(7.12);
  Kwadrat k2(10.57);
  Kwadrat k3 = k1 + k2;
  std::cout << "Obwód k1: " << k1.obwód() << "\n";
  std::cout << "Obwód k2: " << k2.obwód() << "\n";
  std::cout << "Obwód k3: " << k3.obwód() << "\n";

  std::cout << "Większy obwód (t1, k1): " << większy_obwód<Trójkąt, Kwadrat>(t1, k1) << "\n";
  std::cout << "Większy obwód (t3, t2): " << większy_obwód<Trójkąt, Trójkąt>(t3, t2) << "\n";
  std::cout << "Większy obwód (k2, k3): " << większy_obwód<Kwadrat, Kwadrat>(k2, k3) << "\n";

  return 0;
};
