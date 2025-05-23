
class IButton {
 public:
  virtual void draw() const = 0;
};

class LinuxButton : public IButton {
 public:
  void draw() const;
};

class WindowsButton : public IButton {
 public:
  void draw() const;
};

class LegacyButton : public IButton {
 public:
  void draw() const;
};

class LegacyButtonAdapter : public IButton {
 public:
  LegacyButtonAdapter(LegacyButton* button);
  void draw() const;

 private:
  LegacyButton* button_;
};
