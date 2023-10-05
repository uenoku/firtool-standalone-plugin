add_llvm_library(StandalonePlugin
        # BUILDTREE_ONLY is only for testing purposes
        MODULE BUILDTREE_ONLY
        standalone-plugin.cpp

        DEPENDS
        CIRCTStandalone
        CIRCTFIRRTL
        PLUGIN_TOOL
        mlir-opt

        LINK_LIBS
        CIRCTStandalone
        CIRCTFIRRTL
        )
target_include_directories(
        StandalonePlugin
        PRIVATE
        "${STANDALONE_BINARY_DIR}/include"
)
