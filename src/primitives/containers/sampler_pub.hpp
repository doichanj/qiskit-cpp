/*
# This code is part of Qiskit.
#
# (C) Copyright IBM 2017, 2024.
#
# This code is licensed under the Apache License, Version 2.0. You may
# obtain a copy of this license in the LICENSE.txt file in the root directory
# of this source tree or at http://www.apache.org/licenses/LICENSE-2.0.
#
# Any modifications or derivative works of this code must retain this
# copyright notice, and modified files need to carry a notice indicating
# that they have been altered from the originals.
*/

// sampler pub definition

#ifndef __qiskitcpp_primitives_sampler_pub_def_hpp__
#define __qiskitcpp_primitives_sampler_pub_def_hpp__

#include <nlohmann/json.hpp>
using json = nlohmann::json;

#include "circuit/quantumcircuit.hpp"
#include "primitives/containers/circuit_serialization.hpp"


namespace Qiskit {
namespace primitives {

static circuit::QuantumCircuit default_circ;

/// @class SamplerPub
/// @brief Sampler Pub(Primitive Unified Bloc)
class SamplerPub {
protected:
    circuit::QuantumCircuit circuit_;
    //std::vector<std::string> params_;     //Parameter will be supported Qiskit 2.2 or higher
    //std::vector<double> values_;
    uint_t shots_ = 0;
    CircuitSerialization serialization_ = default_circuit_serialization();
public:
    /// @brief Create a new SamplerPub
    SamplerPub() {}

    /*
    /// @brief Create a new SamplerPub
    /// @param circ a QuantumCircuit
    /// @param params parameter names
    /// @param values parameter values
    /// @param shots The total number of shots to sample for this sampler pub
    SamplerPub(circuit::QuantumCircuit& circ, std::vector<std::string> params, std::vector<double> values, uint_t shots) : circuit_(circ)
    {
        params_ = params;
        values_ = values;
        shots_ = shots;
    }
    */

    /// @brief Create a new SamplerPub
    /// @param circ a QuantumCircuit
    /// @param shots The total number of shots to sample for this sampler pub
    SamplerPub(circuit::QuantumCircuit& circ, uint_t shots = 0)
    {
        circuit_ = circ;
        shots_ = shots;
    }

    /// @brief Create a new SamplerPub as a copy of src.
    /// @param src a SamplerPub
    SamplerPub(const SamplerPub& src)
    {
        circuit_ = src.circuit_;
        shots_ = src.shots_;
        serialization_ = src.serialization_;
    }
    ~SamplerPub(){}

    /// @brief Return a QuantumCircuit for this sampler pub
    /// @return a quantum circuit
    const circuit::QuantumCircuit& circuit(void) const
    {
        return circuit_;
    }

    /*
    /// @brief Return a list of parameter names for this sampler pub
    std::vector<std::string>& params(void)
    {
        return params_;
    }

    /// @brief Return a list of parameter values for this sampler pub
    std::vector<double>& values(void)
    {
        return values_;
    }
    */

    /// @brief Return the total number of shots
    uint_t shots(void)
    {
        return shots_;
    }

    /// @brief Return the serialization used for this pub's circuit
    /// @return the serialization
    CircuitSerialization serialization(void) const
    {
        return serialization_;
    }

    /// @brief Set the serialization used for this pub's circuit
    /// @param serialization the serialization to use
    /// @note QPY is the default where available and round-trips the circuit
    ///   losslessly. OpenQASM 3 remains accepted by Qiskit Runtime and can be
    ///   selected here as a fallback.
    void set_serialization(const CircuitSerialization serialization)
    {
        serialization_ = serialization;
    }

    /// @brief Return a JSON format of this sampler pub
    /// @return a JSON format sampler pub
    nlohmann::ordered_json to_json(void)
    {
        // TO DO: insert parameters here when Parameter will be supported
        nlohmann::ordered_json params = nlohmann::ordered_json::array();

        // Built up element by element rather than from an initializer list so
        // that the circuit stays an ordered_json throughout. Going through the
        // unordered nlohmann::json would re-sort the keys of the QPY payload
        // object.
        nlohmann::ordered_json ret = nlohmann::ordered_json::array();
        ret.push_back(serialize_pub_circuit(circuit_, serialization_));
        ret.push_back(params);
        if (shots_ > 0) {
            ret.push_back(shots_);
        }
        return ret;
    }

};

} // namespace primitives
} // namespace Qiskit


#endif //__qiskitcpp_primitives_sampler_pub_def_hpp__
