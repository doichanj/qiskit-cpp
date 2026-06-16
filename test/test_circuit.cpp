// This code is part of Qiskit.
//
// (C) Copyright IBM 2025.
//
// This code is licensed under the Apache License, Version 2.0. You may
// obtain a copy of this license in the LICENSE.txt file in the root directory
// of this source tree or at http://www.apache.org/licenses/LICENSE-2.0.
//
// Any modifications or derivative works of this code must retain this
// copyright notice, and modified files need to carry a notice indicating
// that they have been altered from the originals.

#include <iostream>
#include <cstdint>
#include <stdexcept>

#include "common.hpp"

#include "circuit/quantumcircuit.hpp"
using namespace Qiskit;
using namespace Qiskit::circuit;

static int test_standard_gates(void) {
    auto circ = QuantumCircuit(4, 4);
    uint_t count = 0;
    CircuitInstruction op;
    std::string name;
    reg_t qubits;
    std::vector<Parameter> params;

    circ.i(0);
    op = circ[count++];
    name = op.instruction().name();
    qubits = op.qubits();
    if (name != "id" || qubits[0] != 0) {
        std::cerr << "  standard gate test : id (0) != " << name << " (" << qubits[0] << ")" << std::endl;
        return EqualityError;
    }

    circ.h(1);
    op = circ[count++];
    name = op.instruction().name();
    qubits = op.qubits();
    if (name != "h" || qubits[0] != 1) {
        std::cerr << "  standard gate test : h (1) != " << name << " (" << qubits[0] << ")" << std::endl;
        return EqualityError;
    }

    circ.x(0);
    op = circ[count++];
    name = op.instruction().name();
    qubits = op.qubits();
    if (name != "x" || qubits[0] != 0) {
        std::cerr << "  standard gate test : x (0) != " << name << " (" << qubits[0] << ")" << std::endl;
        return EqualityError;
    }

    circ.y(0);
    op = circ[count++];
    name = op.instruction().name();
    qubits = op.qubits();
    if (name != "y" || qubits[0] != 0) {
        std::cerr << "  standard gate test : y (0) != " << name << " (" << qubits[0] << ")" << std::endl;
        return EqualityError;
    }

    circ.z(0);
    op = circ[count++];
    name = op.instruction().name();
    qubits = op.qubits();
    if (name != "z" || qubits[0] != 0) {
        std::cerr << "  standard gate test : z (0) != " << name << " (" << qubits[0] << ")" << std::endl;
        return EqualityError;
    }

    circ.ch(0, 2);
    op = circ[count++];
    name = op.instruction().name();
    qubits = op.qubits();
    if (name != "ch" || qubits[0] != 0 || qubits[1] != 2) {
        std::cerr << "  standard gate test : cx (0, 1) != " << name << " (" << qubits[0] << ", " << qubits[1] << ")" << std::endl;
        return EqualityError;
    }

    circ.cx(0, 1);
    op = circ[count++];
    name = op.instruction().name();
    qubits = op.qubits();
    if (name != "cx" || qubits[0] != 0 || qubits[1] != 1) {
        std::cerr << "  standard gate test : cx (0, 1) != " << name << " (" << qubits[0] << ", " << qubits[1] << ")" << std::endl;
        return EqualityError;
    }

    circ.cy(0, 1);
    op = circ[count++];
    name = op.instruction().name();
    qubits = op.qubits();
    if (name != "cy" || qubits[0] != 0 || qubits[1] != 1) {
        std::cerr << "  standard gate test : cx (0, 1) != " << name << " (" << qubits[0] << ", " << qubits[1] << ")" << std::endl;
        return EqualityError;
    }

    circ.cz(0, 1);
    op = circ[count++];
    name = op.instruction().name();
    qubits = op.qubits();
    if (name != "cz" || qubits[0] != 0 || qubits[1] != 1) {
        std::cerr << "  standard gate test : cz (0, 1) != " << name << " (" << qubits[0] << ", " << qubits[1] << ")" << std::endl;
        return EqualityError;
    }

    circ.p(0.5, 1);
    op = circ[count++];
    name = op.instruction().name();
    qubits = op.qubits();
    params = op.instruction().params();
    if (name != "p" || qubits[0] != 1 || params[0] != 0.5) {
        std::cerr << "  standard gate test : p 0.5 (1) != " << name << " " << params[0] << " (" << qubits[0] << ")" << std::endl;
        return EqualityError;
    }

    circ.r(0.1, 0.2, 2);
    op = circ[count++];
    name = op.instruction().name();
    qubits = op.qubits();
    params = op.instruction().params();
    if (name != "r" || qubits[0] != 2 || params[0] != 0.1 || params[1] != 0.2) {
        std::cerr << "  standard gate test : r 0.1 0.2 (2) != " << name << " " << params[0] << " " << params[1] << " (" << qubits[0] << ")" << std::endl;
        return EqualityError;
    }

    circ.rx(0.3, 0);
    op = circ[count++];
    name = op.instruction().name();
    qubits = op.qubits();
    params = op.instruction().params();
    if (name != "rx" || qubits[0] != 0 || params[0] != 0.3) {
        std::cerr << "  standard gate test : rx 0.3 (0) != " << name << " " << params[0] << " (" << qubits[0] << ")" << std::endl;
        return EqualityError;
    }

    circ.ry(0.3, 1);
    op = circ[count++];
    name = op.instruction().name();
    qubits = op.qubits();
    params = op.instruction().params();
    if (name != "ry" || qubits[0] != 1 || params[0] != 0.3) {
        std::cerr << "  standard gate test : rx 0.3 (1) != " << name << " " << params[0] << " (" << qubits[0] << ")" << std::endl;
        return EqualityError;
    }

    circ.rz(0.3, 2);
    op = circ[count++];
    name = op.instruction().name();
    qubits = op.qubits();
    params = op.instruction().params();
    if (name != "rz" || qubits[0] != 2 || params[0] != 0.3) {
        std::cerr << "  standard gate test : rz 0.3 (2) != " << name << " " << params[0] << " (" << qubits[0] << ")" << std::endl;
        return EqualityError;
    }

    circ.s(0);
    op = circ[count++];
    name = op.instruction().name();
    qubits = op.qubits();
    if (name != "s" || qubits[0] != 0) {
        std::cerr << "  standard gate test : s (0) != " << name << " (" << qubits[0] << ")" << std::endl;
        return EqualityError;
    }

    circ.sdg(1);
    op = circ[count++];
    name = op.instruction().name();
    qubits = op.qubits();
    if (name != "sdg" || qubits[0] != 1) {
        std::cerr << "  standard gate test : sdg (1) != " << name << " (" << qubits[0] << ")" << std::endl;
        return EqualityError;
    }

    circ.sx(2);
    op = circ[count++];
    name = op.instruction().name();
    qubits = op.qubits();
    if (name != "sx" || qubits[0] != 2) {
        std::cerr << "  standard gate test : sx (2) != " << name << " (" << qubits[0] << ")" << std::endl;
        return EqualityError;
    }

    circ.sxdg(3);
    op = circ[count++];
    name = op.instruction().name();
    qubits = op.qubits();
    if (name != "sxdg" || qubits[0] != 3) {
        std::cerr << "  standard gate test : sxdg (3) != " << name << " (" << qubits[0] << ")" << std::endl;
        return EqualityError;
    }

    circ.t(0);
    op = circ[count++];
    name = op.instruction().name();
    qubits = op.qubits();
    if (name != "t" || qubits[0] != 0) {
        std::cerr << "  standard gate test : t (0) != " << name << " (" << qubits[0] << ")" << std::endl;
        return EqualityError;
    }

    circ.tdg(1);
    op = circ[count++];
    name = op.instruction().name();
    qubits = op.qubits();
    if (name != "tdg" || qubits[0] != 1) {
        std::cerr << "  standard gate test : tdg (1) != " << name << " (" << qubits[0] << ")" << std::endl;
        return EqualityError;
    }

    circ.u(0.1, 0.2, 0.3, 0);
    op = circ[count++];
    name = op.instruction().name();
    qubits = op.qubits();
    params = op.instruction().params();
    if (name != "u" || qubits[0] != 0 || params[0] != 0.1 || params[1] != 0.2 || params[2] != 0.3) {
        std::cerr << "  standard gate test : u 0.1 0.2 0.3 (0) != " << name << " " << params[0] << " " << params[1] <<  " " << params[2] << " (" << qubits[0] << ")" << std::endl;
        return EqualityError;
    }

    circ.u1(0.5, 1);
    op = circ[count++];
    name = op.instruction().name();
    qubits = op.qubits();
    params = op.instruction().params();
    if (name != "u1" || qubits[0] != 1 || params[0] != 0.5) {
        std::cerr << "  standard gate test : u1 0.5 (1) != " << name << " " << params[0] << " (" << qubits[0] << ")" << std::endl;
        return EqualityError;
    }

    circ.u2(0.1, 0.2, 2);
    op = circ[count++];
    name = op.instruction().name();
    qubits = op.qubits();
    params = op.instruction().params();
    if (name != "u2" || qubits[0] != 2 || params[0] != 0.1 || params[1] != 0.2) {
        std::cerr << "  standard gate test : u2 0.1 0.2 (2) != " << name << " " << params[0] << " " << params[1] << " (" << qubits[0] << ")" << std::endl;
        return EqualityError;
    }

    circ.u3(0.1, 0.2, 0.3, 0);
    op = circ[count++];
    name = op.instruction().name();
    qubits = op.qubits();
    params = op.instruction().params();
    if (name != "u3" || qubits[0] != 0 || params[0] != 0.1 || params[1] != 0.2 || params[2] != 0.3) {
        std::cerr << "  standard gate test : u3 0.1 0.2 0.3 (0) != " << name << " " << params[0] << " " << params[1] <<  " " << params[2] << " (" << qubits[0] << ")" << std::endl;
        return EqualityError;
    }

    circ.dcx(1, 3);
    op = circ[count++];
    name = op.instruction().name();
    qubits = op.qubits();
    if (name != "dcx" || qubits[0] != 1 || qubits[1] != 3) {
        std::cerr << "  standard gate test : dcx (1, 3) != " << name << " (" << qubits[0] << ", " << qubits[1] << ")" << std::endl;
        return EqualityError;
    }

    circ.ecr(0, 2);
    op = circ[count++];
    name = op.instruction().name();
    qubits = op.qubits();
    if (name != "ecr" || qubits[0] != 0 || qubits[1] != 2) {
        std::cerr << "  standard gate test : ecr (0, 2) != " << name << " (" << qubits[0] << ", " << qubits[1] << ")" << std::endl;
        return EqualityError;
    }

    circ.swap(1, 3);
    op = circ[count++];
    name = op.instruction().name();
    qubits = op.qubits();
    if (name != "swap" || qubits[0] != 1 || qubits[1] != 3) {
        std::cerr << "  standard gate test : swap (1, 3) != " << name << " (" << qubits[0] << ", " << qubits[1] << ")" << std::endl;
        return EqualityError;
    }

    circ.iswap(2, 3);
    op = circ[count++];
    name = op.instruction().name();
    qubits = op.qubits();
    if (name != "iswap" || qubits[0] != 2 || qubits[1] != 3) {
        std::cerr << "  standard gate test : iswap (2, 3) != " << name << " (" << qubits[0] << ", " << qubits[1] << ")" << std::endl;
        return EqualityError;
    }

    circ.cp(0.5, 0, 1);
    op = circ[count++];
    name = op.instruction().name();
    qubits = op.qubits();
    params = op.instruction().params();
    if (name != "cp" || qubits[0] != 0 || qubits[1] != 1 || params[0] != 0.5) {
        std::cerr << "  standard gate test : cp 0.5 (0, 1) != " << name << " " << params[0] << " " << params[1] << " (" << qubits[0] << ")" << std::endl;
        return EqualityError;
    }

    circ.crx(0.1, 1, 2);
    op = circ[count++];
    name = op.instruction().name();
    qubits = op.qubits();
    params = op.instruction().params();
    if (name != "crx" || qubits[0] != 1 || qubits[1] != 2 || params[0] != 0.1) {
        std::cerr << "  standard gate test : crx 0.1 (1, 2) != " << name << " " << params[0] << " " << params[1] << " (" << qubits[0] << ")" << std::endl;
        return EqualityError;
    }

    circ.cry(0.2, 2, 3);
    op = circ[count++];
    name = op.instruction().name();
    qubits = op.qubits();
    params = op.instruction().params();
    if (name != "cry" || qubits[0] != 2 || qubits[1] != 3 || params[0] != 0.2) {
        std::cerr << "  standard gate test : cry 0.2 (2, 3) != " << name << " " << params[0] << " " << params[1] << " (" << qubits[0] << ")" << std::endl;
        return EqualityError;
    }

    circ.crz(0.3, 3, 0);
    op = circ[count++];
    name = op.instruction().name();
    qubits = op.qubits();
    params = op.instruction().params();
    if (name != "crz" || qubits[0] != 3 || qubits[1] != 0 || params[0] != 0.3) {
        std::cerr << "  standard gate test : crz 0.3 (3, 0) != " << name << " " << params[0] << " " << params[1] << " (" << qubits[0] << ")" << std::endl;
        return EqualityError;
    }

    circ.cs(1, 2);
    op = circ[count++];
    name = op.instruction().name();
    qubits = op.qubits();
    if (name != "cs" || qubits[0] != 1 || qubits[1] != 2) {
        std::cerr << "  standard gate test : cs (1, 2) != " << name << " (" << qubits[0] << ", " << qubits[1] << ")" << std::endl;
        return EqualityError;
    }

    circ.csdg(1, 3);
    op = circ[count++];
    name = op.instruction().name();
    qubits = op.qubits();
    if (name != "csdg" || qubits[0] != 1 || qubits[1] != 3) {
        std::cerr << "  standard gate test : csdg (1, 3) != " << name << " (" << qubits[0] << ", " << qubits[1] << ")" << std::endl;
        return EqualityError;
    }

    circ.csx(3, 0);
    op = circ[count++];
    name = op.instruction().name();
    qubits = op.qubits();
    if (name != "csx" || qubits[0] != 3 || qubits[1] != 0) {
        std::cerr << "  standard gate test : csx (3, 0) != " << name << " (" << qubits[0] << ", " << qubits[1] << ")" << std::endl;
        return EqualityError;
    }

    circ.cu(0.1, 0.2, 0.3, 0, 1);
    op = circ[count++];
    name = op.instruction().name();
    qubits = op.qubits();
    params = op.instruction().params();
    if (name != "cu" || qubits[0] != 0 || qubits[1] != 1 || params[0] != 0.1 || params[1] != 0.2 || params[2] != 0.3) {
        std::cerr << "  standard gate test : cu 0.1 0.2 0.3 (0, 1) != " << name << " " << params[0] << " " << params[1] <<  " " << params[2] << " (" << qubits[0] <<  ", " << qubits[1] << ")" << std::endl;
        return EqualityError;
    }

    circ.cu1(0.5, 0, 1);
    op = circ[count++];
    name = op.instruction().name();
    qubits = op.qubits();
    params = op.instruction().params();
    if (name != "cu1" || qubits[0] != 0 || qubits[1] != 1 || params[0] != 0.5) {
        std::cerr << "  standard gate test : cu1 0.5 (0, 1) != " << name << " " << params[0] << " (" << qubits[0] <<  ", " << qubits[1] << ")" << std::endl;
        return EqualityError;
    }

    circ.cu3(0.1, 0.2, 0.3, 0, 1);
    op = circ[count++];
    name = op.instruction().name();
    qubits = op.qubits();
    params = op.instruction().params();
    if (name != "cu3" || qubits[0] != 0 || qubits[1] != 1 || params[0] != 0.1 || params[1] != 0.2 || params[2] != 0.3) {
        std::cerr << "  standard gate test : cu3 0.1 0.2 0.3 (0, 1) != " << name << " " << params[0] << " " << params[1] <<  " " << params[2] << " (" << qubits[0] <<  ", " << qubits[1] << ")" << std::endl;
        return EqualityError;
    }

    circ.rxx(0.1, 1, 2);
    op = circ[count++];
    name = op.instruction().name();
    qubits = op.qubits();
    params = op.instruction().params();
    if (name != "rxx" || qubits[0] != 1 || qubits[1] != 2 || params[0] != 0.1) {
        std::cerr << "  standard gate test : rxx 0.1 (1, 2) != " << name << " " << params[0] << " " << params[1] << " (" << qubits[0] << ")" << std::endl;
        return EqualityError;
    }

    circ.ryy(0.1, 1, 2);
    op = circ[count++];
    name = op.instruction().name();
    qubits = op.qubits();
    params = op.instruction().params();
    if (name != "ryy" || qubits[0] != 1 || qubits[1] != 2 || params[0] != 0.1) {
        std::cerr << "  standard gate test : ryy 0.1 (1, 2) != " << name << " " << params[0] << " " << params[1] << " (" << qubits[0] << ")" << std::endl;
        return EqualityError;
    }

    circ.rzz(0.1, 1, 2);
    op = circ[count++];
    name = op.instruction().name();
    qubits = op.qubits();
    params = op.instruction().params();
    if (name != "rzz" || qubits[0] != 1 || qubits[1] != 2 || params[0] != 0.1) {
        std::cerr << "  standard gate test : rzz 0.1 (1, 2) != " << name << " " << params[0] << " " << params[1] << " (" << qubits[0] << ")" << std::endl;
        return EqualityError;
    }

    circ.rzx(0.1, 1, 2);
    op = circ[count++];
    name = op.instruction().name();
    qubits = op.qubits();
    params = op.instruction().params();
    if (name != "rzx" || qubits[0] != 1 || qubits[1] != 2 || params[0] != 0.1) {
        std::cerr << "  standard gate test : rzx 0.1 (1, 2) != " << name << " " << params[0] << " " << params[1] << " (" << qubits[0] << ")" << std::endl;
        return EqualityError;
    }

    circ.xx_plus_yy(0.1, 0.2, 0, 2);
    op = circ[count++];
    name = op.instruction().name();
    qubits = op.qubits();
    params = op.instruction().params();
    if (name != "xx_plus_yy" || qubits[0] != 0 || qubits[1] != 2 || params[0] != 0.1 || params[1] != 0.2) {
        std::cerr << "  standard gate test : xx_plus_yy 0.1 0.2 (0, 2) != " << name << " " << params[0] << " " << params[1] << " " << params[1] << " (" << qubits[0] << ")" << std::endl;
        return EqualityError;
    }

    circ.xx_minus_yy(0.3, 0.4, 1, 3);
    op = circ[count++];
    name = op.instruction().name();
    qubits = op.qubits();
    params = op.instruction().params();
    if (name != "xx_minus_yy" || qubits[0] != 1 || qubits[1] != 3 || params[0] != 0.3 || params[1] != 0.4) {
        std::cerr << "  standard gate test : xx_minus_yy 0.3 0.4 (1, 3) != " << name << " " << params[0] << " " << params[1] << " " << params[1] << " (" << qubits[0] << ")" << std::endl;
        return EqualityError;
    }

    circ.ccx(0, 1, 2);
    op = circ[count++];
    name = op.instruction().name();
    qubits = op.qubits();
    if (name != "ccx" || qubits[0] != 0 || qubits[1] != 1 || qubits[2] != 2) {
        std::cerr << "  standard gate test : ccx (0, 1, 2) != " << name << " (" << qubits[0] << ", " << qubits[1] <<  ", " << qubits[2] << ")" << std::endl;
        return EqualityError;
    }

    circ.ccz(2, 1, 0);
    op = circ[count++];
    name = op.instruction().name();
    qubits = op.qubits();
    if (name != "ccz" || qubits[0] != 2 || qubits[1] != 1 || qubits[2] != 0) {
        std::cerr << "  standard gate test : ccz (2, 1, 0) != " << name << " (" << qubits[0] << ", " << qubits[1] <<  ", " << qubits[2] << ")" << std::endl;
        return EqualityError;
    }

    circ.cswap(0, 1, 2);
    op = circ[count++];
    name = op.instruction().name();
    qubits = op.qubits();
    if (name != "cswap" || qubits[0] != 0 || qubits[1] != 1 || qubits[2] != 2) {
        std::cerr << "  standard gate test : cswap (0, 1, 2) != " << name << " (" << qubits[0] << ", " << qubits[1] <<  ", " << qubits[2] << ")" << std::endl;
        return EqualityError;
    }

    circ.rccx(0, 1, 2);
    op = circ[count++];
    name = op.instruction().name();
    qubits = op.qubits();
    if (name != "rccx" || qubits[0] != 0 || qubits[1] != 1 || qubits[2] != 2) {
        std::cerr << "  standard gate test : rccx (0, 1, 2) != " << name << " (" << qubits[0] << ", " << qubits[1] <<  ", " << qubits[2] << ")" << std::endl;
        return EqualityError;
    }

    circ.cccx(0, 1, 2, 3);
    op = circ[count++];
    name = op.instruction().name();
    qubits = op.qubits();
    if (name != "mcx" || qubits[0] != 0 || qubits[1] != 1 || qubits[2] != 2 || qubits[3] != 3) {
        std::cerr << "  standard gate test : mcx (0, 1, 2, 3) != " << name << " (" << qubits[0] << ", " << qubits[1] <<  ", " << qubits[2] <<  ", " << qubits[3] << ")" << std::endl;
        return EqualityError;
    }

    circ.cccsx(0, 1, 2, 3);
    op = circ[count++];
    name = op.instruction().name();
    qubits = op.qubits();
    if (name != "c3sx" || qubits[0] != 0 || qubits[1] != 1 || qubits[2] != 2 || qubits[3] != 3) {
        std::cerr << "  standard gate test : c3sx (0, 1, 2, 3) != " << name << " (" << qubits[0] << ", " << qubits[1] <<  ", " << qubits[2] <<  ", " << qubits[3] << ")" << std::endl;
        return EqualityError;
    }

    circ.rcccx(0, 1, 2, 3);
    op = circ[count++];
    name = op.instruction().name();
    qubits = op.qubits();
    if (name != "rcccx" || qubits[0] != 0 || qubits[1] != 1 || qubits[2] != 2 || qubits[3] != 3) {
        std::cerr << "  standard gate test : rcccx (0, 1, 2, 3) != " << name << " (" << qubits[0] << ", " << qubits[1] <<  ", " << qubits[2] <<  ", " << qubits[3] << ")" << std::endl;
        return EqualityError;
    }

    return Ok;
}

static int test_measure(void) {
    uint_t num_qubits = 4;
    auto qr = QuantumRegister(num_qubits);
    auto cr = ClassicalRegister(num_qubits);
    auto circ = QuantumCircuit(qr, cr);

    circ.h(0);
    circ.measure(qr, cr);

    for (uint_t i = 0; i < num_qubits; i++) {
        CircuitInstruction op = circ[i + 1];
        if (op.instruction().name() != "measure" || op.qubits()[0] != i || op.clbits()[0] != i) {
            std::cerr << "  measure test : measure ( " << i << ", " << i << ") != " << op.instruction().name() << " (" << op.qubits()[0] << ", " << op.clbits()[0] << ")" << std::endl;
            return EqualityError;
        }
    }
    return Ok;
}

static int test_append(void) {
    uint_t num_qubits = 4;
    auto circ = QuantumCircuit(num_qubits, num_qubits);
    CircuitInstruction op;
    std::string name;
    reg_t qubits;
    std::vector<Parameter> params;

    circ.h(0);

    circ.append(CXGate(), reg_t({2, 3}));
    op = circ[1];
    name = op.instruction().name();
    qubits = op.qubits();
    if (name != "cx" || qubits[0] != 2 || qubits[1] != 3) {
        std::cerr << "  append test : cx (2, 3) != " << name << " (" << qubits[0] << ", " << qubits[1] << ")" << std::endl;
        return EqualityError;
    }

    RZGate rz;
    rz.set_params({0.5});
    circ.append(rz, 1);

    op = circ[2];
    name = op.instruction().name();
    qubits = op.qubits();
    params = op.instruction().params();
    if (name != "rz" || qubits[0] != 1) {
        std::cerr << "  append test : rz 0.5 (1) != " << name << " " << params[0] << " (" << qubits[0] << ")" << std::endl;
        return EqualityError;
    }

    return Ok;
}

static int test_compose(void) {
    uint_t num_qubits = 4;
    auto circ = QuantumCircuit(num_qubits, num_qubits);
    CircuitInstruction op;
    std::string name;
    reg_t qubits;
    std::vector<Parameter> params;

    circ.h(0);
    for (uint_t i = 1; i < num_qubits; i++) {
        circ.cx(0, i);
    }

    auto sub = QuantumCircuit(2, 2);
    sub.sx(0);
    sub.rz(0.5, 1);

    uint_t num_inst = circ.num_instructions();
    uint_t total = num_inst + sub.num_instructions();

    circ.compose(sub, reg_t({2, 0}), reg_t({2, 0}));

    if (circ.num_instructions() != total) {
        std::cerr << "  compose test : number of instruction " << total << " != " << circ.num_instructions() << std::endl;
        return EqualityError;
    }

    op = circ[num_inst];
    name = op.instruction().name();
    qubits = op.qubits();
    if (name != "sx" || qubits[0] != 2) {
        std::cerr << "  compose test : sx (2) != " << name << " (" << qubits[0] << ")" << std::endl;
        return EqualityError;
    }

    op = circ[num_inst + 1];
    name = op.instruction().name();
    qubits = op.qubits();
    params = op.instruction().params();
    if (name != "rz" || qubits[0] != 0) {
        std::cerr << "  compose test : rz 0.5 (0) != " << name << " " << params[0] << " (" << qubits[0] << ")" << std::endl;
        return EqualityError;
    }

    return Ok;
}

static int test_to_qasm3_multi_regs(void) {
    auto qreg1 = QuantumRegister(2, std::string("q1"));
    auto qreg2 = QuantumRegister(1, std::string("q2"));
    auto creg1 = ClassicalRegister(2, std::string("c1"));
    auto creg2 = ClassicalRegister(1, std::string("c2"));
    QuantumCircuit circ(std::vector<QuantumRegister>({qreg1, qreg2}), std::vector<ClassicalRegister>({creg1, creg2}));

    circ.measure(qreg2, creg2);
    circ.measure(qreg1, creg1);

    const auto actual = circ.to_qasm3();
    const std::string expected =
        "OPENQASM 3.0;\n"
        "include \"stdgates.inc\";\n"
        "qubit[3] q;\n"
        "bit[2] c1;\n"
        "bit[1] c2;\n"
        "c2[0] = measure q[2];\n"
        "c1[0] = measure q[0];\n"
        "c1[1] = measure q[1];\n";
    if (actual != expected) {
        std::cerr << "  to_qasm3_multi_regs test : \n    expected:\n" << expected
            << "\n    actual:\n" << actual << std::endl;
        return EqualityError;
    }

    return Ok;
}

static int test_to_qasm3_parameterized(void) {
    auto qreg = QuantumRegister(2, std::string("q"));
    auto creg = ClassicalRegister(1, std::string("c"));
    QuantumCircuit circ(qreg, creg);
    auto theta = Parameter("theta");
    auto phi = Parameter("phi");
    auto expr = theta + phi;

    circ.rx(theta, 0);
    circ.rz(expr, 1);
    circ.measure(0, 0);

    if (circ.num_parameters() != 2) {
        std::cerr << "  to_qasm3_parameterized test : number of parameters 2 != " << circ.num_parameters() << std::endl;
        return EqualityError;
    }

    const auto actual = circ.to_qasm3();
    const std::string expected =
        "OPENQASM 3.0;\n"
        "include \"stdgates.inc\";\n"
        "input float[64] phi;\n"
        "input float[64] theta;\n"
        "qubit[2] q;\n"
        "bit[1] c;\n"
        "rx(theta) q[0];\n"
        "rz(phi + theta) q[1];\n"
        "c[0] = measure q[0];\n";
    if (actual != expected) {
        std::cerr << "  to_qasm3_parameterized test : \n    expected:\n" << expected
            << "\n    actual:\n" << actual << std::endl;
        return EqualityError;
    }

    return Ok;
}

static int test_to_qasm3_parameter_name_conflicts(void) {
    auto qreg = QuantumRegister(1, std::string("q"));
    auto creg = ClassicalRegister(1, std::string("c"));
    QuantumCircuit circ(qreg, creg);
    auto qparam = Parameter("q");
    auto cparam = Parameter("c");
    auto rzparam = Parameter("rz");
    auto sinparam = Parameter("sin");
    auto measure_param = Parameter("measure");

    circ.rx(qparam, 0);
    circ.ry(cparam, 0);
    circ.rz(rzparam, 0);
    circ.p(sinparam, 0);
    circ.rx(measure_param, 0);
    circ.measure(0, 0);

    if (circ.num_parameters() != 5) {
        std::cerr << "  to_qasm3_parameter_name_conflicts test : number of parameters 5 != " << circ.num_parameters() << std::endl;
        return EqualityError;
    }

    const auto actual = circ.to_qasm3();
    const std::string expected =
        "OPENQASM 3.0;\n"
        "include \"stdgates.inc\";\n"
        "input float[64] c;\n"
        "input float[64] measure_0;\n"
        "input float[64] q;\n"
        "input float[64] rz_0;\n"
        "input float[64] sin;\n"
        "qubit[1] q_0;\n"
        "bit[1] c_0;\n"
        "rx(q) q_0[0];\n"
        "ry(c) q_0[0];\n"
        "rz(rz_0) q_0[0];\n"
        "p(sin) q_0[0];\n"
        "rx(measure_0) q_0[0];\n"
        "c_0[0] = measure q_0[0];\n";
    if (actual != expected) {
        std::cerr << "  to_qasm3_parameter_name_conflicts test : \n    expected:\n" << expected
            << "\n    actual:\n" << actual << std::endl;
        return EqualityError;
    }

    return Ok;
}

static int test_to_qasm3_stdgate_name_conflicts(void) {
    auto qreg = QuantumRegister(1, std::string("q"));
    QuantumCircuit circ(std::vector<QuantumRegister>({qreg}), std::vector<ClassicalRegister>());
    const std::vector<std::string> names = {
        "CX", "cphase", "crx", "cry", "crz", "cswap",
        "cu", "id", "phase", "u1", "u2", "u3"
    };

    for (const auto &name : names) {
        auto param = Parameter(name);
        circ.rx(param, 0);
    }

    if (circ.num_parameters() != names.size()) {
        std::cerr << "  to_qasm3_stdgate_name_conflicts test : number of parameters " << names.size()
            << " != " << circ.num_parameters() << std::endl;
        return EqualityError;
    }

    const auto actual = circ.to_qasm3();
    const std::string expected =
        "OPENQASM 3.0;\n"
        "include \"stdgates.inc\";\n"
        "input float[64] CX_0;\n"
        "input float[64] cphase_0;\n"
        "input float[64] crx_0;\n"
        "input float[64] cry_0;\n"
        "input float[64] crz_0;\n"
        "input float[64] cswap_0;\n"
        "input float[64] cu_0;\n"
        "input float[64] id_0;\n"
        "input float[64] phase_0;\n"
        "input float[64] u1_0;\n"
        "input float[64] u2_0;\n"
        "input float[64] u3_0;\n"
        "qubit[1] q;\n"
        "rx(CX_0) q[0];\n"
        "rx(cphase_0) q[0];\n"
        "rx(crx_0) q[0];\n"
        "rx(cry_0) q[0];\n"
        "rx(crz_0) q[0];\n"
        "rx(cswap_0) q[0];\n"
        "rx(cu_0) q[0];\n"
        "rx(id_0) q[0];\n"
        "rx(phase_0) q[0];\n"
        "rx(u1_0) q[0];\n"
        "rx(u2_0) q[0];\n"
        "rx(u3_0) q[0];\n";
    if (actual != expected) {
        std::cerr << "  to_qasm3_stdgate_name_conflicts test : \n    expected:\n" << expected
            << "\n    actual:\n" << actual << std::endl;
        return EqualityError;
    }

    return Ok;
}

static int test_to_qasm3_keyword_and_constant_name_conflicts(void) {
    auto qreg = QuantumRegister(1, std::string("q"));
    QuantumCircuit circ(std::vector<QuantumRegister>({qreg}), std::vector<ClassicalRegister>());
    const std::vector<std::string> names = {
        "I", "array", "false", "im", "pi", "qreg", "readonly", "switch", "true"
    };

    for (const auto &name : names) {
        auto param = Parameter(name);
        circ.rx(param, 0);
    }

    if (circ.num_parameters() != names.size()) {
        std::cerr << "  to_qasm3_keyword_and_constant_name_conflicts test : number of parameters "
            << names.size() << " != " << circ.num_parameters() << std::endl;
        return EqualityError;
    }

    const auto actual = circ.to_qasm3();
    const std::string expected =
        "OPENQASM 3.0;\n"
        "include \"stdgates.inc\";\n"
        "input float[64] I_0;\n"
        "input float[64] array_0;\n"
        "input float[64] false_0;\n"
        "input float[64] im_0;\n"
        "input float[64] pi_0;\n"
        "input float[64] qreg_0;\n"
        "input float[64] readonly_0;\n"
        "input float[64] switch_0;\n"
        "input float[64] true_0;\n"
        "qubit[1] q;\n"
        "rx(I_0) q[0];\n"
        "rx(array_0) q[0];\n"
        "rx(false_0) q[0];\n"
        "rx(im_0) q[0];\n"
        "rx(pi_0) q[0];\n"
        "rx(qreg_0) q[0];\n"
        "rx(readonly_0) q[0];\n"
        "rx(switch_0) q[0];\n"
        "rx(true_0) q[0];\n";
    if (actual != expected) {
        std::cerr << "  to_qasm3_keyword_and_constant_name_conflicts test : \n    expected:\n" << expected
            << "\n    actual:\n" << actual << std::endl;
        return EqualityError;
    }

    return Ok;
}

static int test_to_qasm3_classical_register_name_conflicts(void) {
    auto qreg = QuantumRegister(1, std::string("q"));
    auto stdgate_creg = ClassicalRegister(1, std::string("cu"));
    auto keyword_creg = ClassicalRegister(1, std::string("creg"));
    QuantumCircuit circ(std::vector<QuantumRegister>({qreg}), std::vector<ClassicalRegister>({stdgate_creg, keyword_creg}));

    circ.measure(qreg, stdgate_creg);
    circ.measure(qreg, keyword_creg);

    const auto actual = circ.to_qasm3();
    const std::string expected =
        "OPENQASM 3.0;\n"
        "include \"stdgates.inc\";\n"
        "qubit[1] q;\n"
        "bit[1] cu_0;\n"
        "bit[1] creg_0;\n"
        "cu_0[0] = measure q[0];\n"
        "creg_0[0] = measure q[0];\n";
    if (actual != expected) {
        std::cerr << "  to_qasm3_classical_register_name_conflicts test : \n    expected:\n" << expected
            << "\n    actual:\n" << actual << std::endl;
        return EqualityError;
    }

    return Ok;
}

static int test_to_qasm3_custom_gate_name_conflicts(void) {
    auto qreg = QuantumRegister(2, std::string("q"));
    auto creg = ClassicalRegister(1, std::string("rzz"));
    QuantumCircuit circ(qreg, creg);
    auto rzzparam = Parameter("rzz");

    circ.rzz(rzzparam, 0, 1);
    circ.measure(0, 0);

    if (circ.num_parameters() != 1) {
        std::cerr << "  to_qasm3_custom_gate_name_conflicts test : number of parameters 1 != " << circ.num_parameters() << std::endl;
        return EqualityError;
    }

    const auto actual = circ.to_qasm3();
    const std::string expected =
        "OPENQASM 3.0;\n"
        "include \"stdgates.inc\";\n"
        "input float[64] rzz_0;\n"
        "gate rzz(p0) _gate_q_0, _gate_q_1 {\n"
        "  cx _gate_q_0, _gate_q_1;\n"
        "  rz(p0) _gate_q_1;\n"
        "  cx _gate_q_0, _gate_q_1;\n"
        "}\n"
        "qubit[2] q;\n"
        "bit[1] rzz_1;\n"
        "rzz(rzz_0) q[0], q[1];\n"
        "rzz_1[0] = measure q[0];\n";
    if (actual != expected) {
        std::cerr << "  to_qasm3_custom_gate_name_conflicts test : \n    expected:\n" << expected
            << "\n    actual:\n" << actual << std::endl;
        return EqualityError;
    }

    return Ok;
}

static int test_to_qasm3_cu1_definition(void) {
    auto qreg = QuantumRegister(2, std::string("q"));
    QuantumCircuit circ(std::vector<QuantumRegister>({qreg}), std::vector<ClassicalRegister>());
    auto theta = Parameter("theta");

    circ.cu1(theta, 0, 1);

    if (circ.num_parameters() != 1) {
        std::cerr << "  to_qasm3_cu1_definition test : number of parameters 1 != " << circ.num_parameters() << std::endl;
        return EqualityError;
    }

    const auto actual = circ.to_qasm3();
    const std::string expected =
        "OPENQASM 3.0;\n"
        "include \"stdgates.inc\";\n"
        "input float[64] theta;\n"
        "gate cu1(p0) _gate_q_0, _gate_q_1 {\n"
        "  cp(p0) _gate_q_0, _gate_q_1;\n"
        "}\n"
        "qubit[2] q;\n"
        "cu1(theta) q[0], q[1];\n";
    if (actual != expected) {
        std::cerr << "  to_qasm3_cu1_definition test : \n    expected:\n" << expected
            << "\n    actual:\n" << actual << std::endl;
        return EqualityError;
    }

    return Ok;
}

static int test_to_qasm3_cu3_definition(void) {
    auto qreg = QuantumRegister(2, std::string("q"));
    QuantumCircuit circ(std::vector<QuantumRegister>({qreg}), std::vector<ClassicalRegister>());
    auto theta = Parameter("theta");
    auto phi = Parameter("phi");
    auto lam = Parameter("lam");

    circ.cu3(theta, phi, lam, 0, 1);

    if (circ.num_parameters() != 3) {
        std::cerr << "  to_qasm3_cu3_definition test : number of parameters 3 != " << circ.num_parameters() << std::endl;
        return EqualityError;
    }

    const auto actual = circ.to_qasm3();
    const std::string expected =
        "OPENQASM 3.0;\n"
        "include \"stdgates.inc\";\n"
        "input float[64] lam;\n"
        "input float[64] phi;\n"
        "input float[64] theta;\n"
        "gate cu3(p0, p1, p2) _gate_q_0, _gate_q_1 {\n"
        "  cu(p0, p1, p2, 0) _gate_q_0, _gate_q_1;\n"
        "}\n"
        "qubit[2] q;\n"
        "cu3(theta, phi, lam) q[0], q[1];\n";
    if (actual != expected) {
        std::cerr << "  to_qasm3_cu3_definition test : \n    expected:\n" << expected
            << "\n    actual:\n" << actual << std::endl;
        return EqualityError;
    }

    return Ok;
}

static int test_to_qasm3_global_phase(void) {
    auto qreg = QuantumRegister(1, std::string("q"));
    QuantumCircuit circ(std::vector<QuantumRegister>({qreg}), std::vector<ClassicalRegister>(), 0.5);

    circ.h(0);

    const auto actual = circ.to_qasm3();
    const std::string expected =
        "OPENQASM 3.0;\n"
        "include \"stdgates.inc\";\n"
        "qubit[1] q;\n"
        "gphase(0.5);\n"
        "h q[0];\n";
    if (actual != expected) {
        std::cerr << "  to_qasm3_global_phase test : \n    expected:\n" << expected
            << "\n    actual:\n" << actual << std::endl;
        return EqualityError;
    }

    return Ok;
}

static int test_to_qasm3_physical_qubits(void) {
    auto circ = QuantumCircuit(156, 0);
    circ.h(21);
    circ.cx(21, 22);

    std::vector<std::uint32_t> layout({21, 22});
    circ.set_qiskit_circuit(circ.get_rust_circuit(), layout);

    const auto actual = circ.to_qasm3();
    const std::string expected =
        "OPENQASM 3.0;\n"
        "include \"stdgates.inc\";\n"
        "h $21;\n"
        "cx $21, $22;\n";
    if (actual != expected) {
        std::cerr << "  to_qasm3_physical_qubits test : \n    expected:\n" << expected
            << "\n    actual:\n" << actual << std::endl;
        return EqualityError;
    }

    return Ok;
}

static int test_parameter_symbols(void) {
    auto qreg = QuantumRegister(2, std::string("q"));
    QuantumCircuit circ(std::vector<QuantumRegister>({qreg}), std::vector<ClassicalRegister>());
    auto theta = Parameter("theta");
    auto phi = Parameter("phi");
    auto qparam = Parameter("q");
    auto sinparam = Parameter("sin");
    auto measure_param = Parameter("measure");

    circ.rx(theta, 0);
    circ.rz(theta + phi, 1);   // reuse theta; function-style names must not leak
    circ.p((phi * 2.0).sin(), 0);
    circ.rx(qparam, 0);
    circ.ry(sinparam, 1);
    circ.rz(measure_param, 0);

    const auto symbols = circ.parameter_symbols();

    // Names are original, unique, sorted, and exclude QASM math function tokens.
    const std::vector<std::string> expected = {"measure", "phi", "q", "sin", "theta"};
    if (symbols != expected) {
        std::cerr << "  parameter_symbols test : unexpected list, got:";
        for (const auto &s : symbols) std::cerr << " " << s;
        std::cerr << std::endl;
        return EqualityError;
    }

    // The derived list must stay consistent with the Rust-side symbol count.
    if (symbols.size() != circ.num_parameters()) {
        std::cerr << "  parameter_symbols test : size " << symbols.size()
            << " != num_parameters " << circ.num_parameters() << std::endl;
        return EqualityError;
    }

    return Ok;
}

static int test_parameter_symbols_unsupported_name(void) {
    auto qreg = QuantumRegister(1, std::string("q"));
    QuantumCircuit circ(std::vector<QuantumRegister>({qreg}), std::vector<ClassicalRegister>());
    auto param = Parameter("a-b");

    circ.rx(param, 0);

    try {
        circ.parameter_symbols();
    } catch (const std::runtime_error &err) {
        const std::string message = err.what();
        if (message.find("parameter_symbols cannot derive") == std::string::npos) {
            std::cerr << "  parameter_symbols_unsupported_name test : unexpected error: "
                << message << std::endl;
            return EqualityError;
        }
        return Ok;
    }

    std::cerr << "  parameter_symbols_unsupported_name test : expected runtime_error"
        << std::endl;
    return EqualityError;
}

// Documented limitation (per maintainer review on PR #159): qiskit-cpp cannot
// disambiguate distinct Parameter objects that share a name (no UUID through the
// C-API), so they collapse onto a single shared symbol of that name. This case
// is deliberately not detected or rejected -- preflight-copying the circuit on
// every parameterized gate just to detect it is too expensive. The exported
// OpenQASM 3 stays valid; the colliding gates simply bind the same input. Use a
// unique name per distinct parameter to avoid this.
static int test_parameter_symbols_duplicate_name_limitation(void) {
    // Two distinct Parameter("a") objects across separate gates collapse to one
    // symbol "a"; both gates reference it and the QASM remains valid.
    {
        QuantumCircuit circ(2, 0);
        auto a0 = Parameter("a");
        auto a1 = Parameter("a");
        circ.rx(a0, 0);
        circ.ry(a1, 1);

        if (circ.num_parameters() != 1) {
            std::cerr << "  parameter_symbols_duplicate_name_limitation test : expected 1 collapsed "
                << "symbol, got " << circ.num_parameters() << std::endl;
            return EqualityError;
        }
        const auto symbols = circ.parameter_symbols();
        if (symbols != std::vector<std::string>({"a"})) {
            std::cerr << "  parameter_symbols_duplicate_name_limitation test : unexpected symbol list, got:";
            for (const auto &s : symbols) std::cerr << " " << s;
            std::cerr << std::endl;
            return EqualityError;
        }

        const std::string expected =
            "OPENQASM 3.0;\n"
            "include \"stdgates.inc\";\n"
            "input float[64] a;\n"
            "qubit[2] q;\n"
            "rx(a) q[0];\n"
            "ry(a) q[1];\n";
        if (circ.to_qasm3() != expected) {
            std::cerr << "  parameter_symbols_duplicate_name_limitation test : \n    expected:\n" << expected
                << "\n    actual:\n" << circ.to_qasm3() << std::endl;
            return EqualityError;
        }
    }

    // The same collapse happens for duplicate names within a single
    // multi-parameter gate.
    {
        QuantumCircuit circ(1, 0);
        auto b0 = Parameter("b");
        auto b1 = Parameter("b");
        circ.r(b0, b1, 0);

        if (circ.num_parameters() != 1
            || circ.parameter_symbols() != std::vector<std::string>({"b"})) {
            std::cerr << "  parameter_symbols_duplicate_name_limitation test : multi-param gate did "
                << "not collapse to a single symbol" << std::endl;
            return EqualityError;
        }
    }

    return Ok;
}

// parameter_symbols() reads the parameter expressions from the Rust circuit, so
// it recovers parameters introduced through compose() without any per-Parameter
// bookkeeping on the C++ side.
static int test_to_qasm3_compose_parameterized(void) {
    auto qreg = QuantumRegister(2, std::string("q"));
    QuantumCircuit circ(std::vector<QuantumRegister>({qreg}), std::vector<ClassicalRegister>());
    QuantumCircuit sub(2, 0);
    auto theta = Parameter("theta");
    auto phi = Parameter("phi");
    sub.rx(theta, 0);
    sub.ry(phi, 1);

    circ.compose(sub, reg_t({0, 1}), reg_t({}));

    const auto symbols = circ.parameter_symbols();
    if (symbols != std::vector<std::string>({"phi", "theta"})) {
        std::cerr << "  to_qasm3_compose_parameterized test : unexpected symbol list, got:";
        for (const auto &s : symbols) std::cerr << " " << s;
        std::cerr << std::endl;
        return EqualityError;
    }

    const auto actual = circ.to_qasm3();
    const std::string expected =
        "OPENQASM 3.0;\n"
        "include \"stdgates.inc\";\n"
        "input float[64] phi;\n"
        "input float[64] theta;\n"
        "qubit[2] q;\n"
        "rx(theta) q[0];\n"
        "ry(phi) q[1];\n";
    if (actual != expected) {
        std::cerr << "  to_qasm3_compose_parameterized test : \n    expected:\n" << expected
            << "\n    actual:\n" << actual << std::endl;
        return EqualityError;
    }

    return Ok;
}

// parameters introduced through append() of an existing instruction are likewise
// recovered, because the symbol list is derived from the Rust circuit.
static int test_to_qasm3_append_parameterized(void) {
    QuantumCircuit src(1, 0);
    auto theta = Parameter("theta");
    src.rx(theta, 0);

    QuantumCircuit dst(1, 0);
    dst.append(src[0]);

    const auto symbols = dst.parameter_symbols();
    if (symbols != std::vector<std::string>({"theta"})) {
        std::cerr << "  to_qasm3_append_parameterized test : unexpected symbol list, got:";
        for (const auto &s : symbols) std::cerr << " " << s;
        std::cerr << std::endl;
        return EqualityError;
    }

    const auto actual = dst.to_qasm3();
    const std::string expected =
        "OPENQASM 3.0;\n"
        "include \"stdgates.inc\";\n"
        "input float[64] theta;\n"
        "qubit[1] q;\n"
        "rx(theta) q[0];\n";
    if (actual != expected) {
        std::cerr << "  to_qasm3_append_parameterized test : \n    expected:\n" << expected
            << "\n    actual:\n" << actual << std::endl;
        return EqualityError;
    }

    return Ok;
}

#if defined(_WIN32)
int test_circuit(int argc, char** const argv) {
#else
int test_circuit(int argc, char** argv) {
#endif
    int num_failed = 0;
    num_failed += RUN_TEST(test_standard_gates);
    num_failed += RUN_TEST(test_measure);
    num_failed += RUN_TEST(test_append);
    num_failed += RUN_TEST(test_compose);
    num_failed += RUN_TEST(test_to_qasm3_multi_regs);
    num_failed += RUN_TEST(test_parameter_symbols);
    num_failed += RUN_TEST(test_parameter_symbols_unsupported_name);
    num_failed += RUN_TEST(test_parameter_symbols_duplicate_name_limitation);
    num_failed += RUN_TEST(test_to_qasm3_compose_parameterized);
    num_failed += RUN_TEST(test_to_qasm3_append_parameterized);
    num_failed += RUN_TEST(test_to_qasm3_parameterized);
    num_failed += RUN_TEST(test_to_qasm3_parameter_name_conflicts);
    num_failed += RUN_TEST(test_to_qasm3_stdgate_name_conflicts);
    num_failed += RUN_TEST(test_to_qasm3_keyword_and_constant_name_conflicts);
    num_failed += RUN_TEST(test_to_qasm3_classical_register_name_conflicts);
    num_failed += RUN_TEST(test_to_qasm3_custom_gate_name_conflicts);
    num_failed += RUN_TEST(test_to_qasm3_cu1_definition);
    num_failed += RUN_TEST(test_to_qasm3_cu3_definition);
    num_failed += RUN_TEST(test_to_qasm3_global_phase);
    num_failed += RUN_TEST(test_to_qasm3_physical_qubits);

    std::cerr << "=== Number of failed subtests: " << num_failed << std::endl;
    return num_failed;
}
