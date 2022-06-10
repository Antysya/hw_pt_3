#pragma once

class Tank {
    float volume;
public:
    Tank(float _volume) { volume = _volume; }
    float getCubicMeter() {
        return volume;
    }
};

class Bottle {
public:
    virtual ~Bottle() {}
    virtual float getBottleLiter() = 0;
};

class Adapter : public Bottle {

public:
    Adapter(Tank* p) : p_fbottle(p) {}
    ~Adapter() { delete p_fbottle; }
    float getBottleLiter() {
        return (p_fbottle->getCubicMeter() * 1000);
    }
private:
    Tank* p_fbottle;
};
