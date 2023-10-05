// RUN: mlir-opt %s --load-dialect-plugin=%standalone_libs/StandalonePlugin%shlibext --pass-pipeline="builtin.module(firrtl.circuit(standalone-switch-bar-foo))" | FileCheck %s

firrtl.circuit "Example" {
  // CHECK-LABEL: %foo = firrtl.wire
  firrtl.module @Example() {
    %bar = firrtl.wire : !firrtl.uint<1>
  }
}
