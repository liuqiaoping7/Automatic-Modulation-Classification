#ifndef AMCDEMODULATOR_H
#define AMCDEMODULATOR_H

#include <complex>
#include <vector>
#include "../amc.h"

/**
 * @brief The AmcDemodulator abstract base class - This class is used to demodulate information that is modulated using AM-DSB-FC/SC.
 * This uses the Liquid-DSP library in order to demodulate the data. Classes that inherit from AmcDemodulator are expected
 * to keep their own state so that only single points are passed to this class.
 *
 * @author Anthony Farquharson - 563648
 * @author Jacques Visser - 457817
 */
class AmcDemodulator
{
public:
    /**
     * @brief AmcDemodulator default constructor, exists so that the base class objects can be created with default
     * functions, the default functions return the data that is put into them.
     */
    AmcDemodulator() {}

    /**
     * @brief The demod function will perform demodulation on the sample that is input to it.
     * Objects that inherit from AmcDemodulator are expected to keep their own state, so that
     * individual data points can be passed for demodulation.
     * @param sampleData
     * @return The return is a real double data point, demodulated from the complex input.
     */
    virtual double demod(const std::complex<double> &sampleData)
    {
        return sampleData.real() + sampleData.imag();
    }

    /**
     * @brief Function for reseting the state information stored by a particular demodulater, incase the
     * state needs to be changed for any particular reason.
     */
    virtual void reset()
    {

    }

    /**
     * @brief Return the modulation type of the relevent class.
     * @return
     */
    virtual AMC::ModType modType()
    {
        return AMC::ModType::MODTYPE_NR_ITEMS;
    }

    virtual ~AmcDemodulator() {}
};

#endif // AMCDEMODULATOR_H
