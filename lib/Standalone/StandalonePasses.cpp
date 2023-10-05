//===- StandalonePasses.cpp - Standalone passes -----------------*- C++ -*-===//
//
// This file is licensed under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
#include "circt/Dialect/FIRRTL/FIRRTLDialect.h"
#include "circt/Dialect/FIRRTL/FIRRTLOps.h"
#include "mlir/Pass/Pass.h"

#include "Standalone/StandalonePasses.h"

namespace mlir::standalone {
#define GEN_PASS_DEF_STANDALONESWITCHBARFOO
#include "Standalone/StandalonePasses.h.inc"

namespace {

class StandaloneSwitchBarFoo
    : public impl::StandaloneSwitchBarFooBase<StandaloneSwitchBarFoo> {
public:
  using impl::StandaloneSwitchBarFooBase<
      StandaloneSwitchBarFoo>::StandaloneSwitchBarFooBase;
  void runOnOperation() final {
    using namespace circt::firrtl;
    CircuitOp circuitOp = getOperation();
    circuitOp.walk([&](WireOp wire) {
      if (wire.getName() == "bar") {
        wire.setName("foo");
      }
    });
  }
};
} // namespace
} // namespace mlir::standalone
